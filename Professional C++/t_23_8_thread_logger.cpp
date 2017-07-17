#include <iostream>
#include <vector>
#include <mutex>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <atomic>

using namespace std;

class Logger
{
public:
	Logger();
	virtual ~Logger();
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& rhs) = delete;
	void log(const std::string& entry);
private:
	std::atomic<bool> mExit;
	void processEntries();
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	std::thread mThread;
};

Logger::Logger() : mExit(false)
{
	mThread = thread(&Logger::processEntries, this);
}

Logger::~Logger()
{
	{
		unique_lock<mutex> lock(mMutex);
		mExit = true;
		mCondVar.notify_all();
	}
	mThread.join();
}

void Logger::log(const std::string& entry)
{
	unique_lock<mutex> lock(mMutex);
	mQueue.push(entry);
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	ofstream ofs("log.txt");
	if (ofs.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}
	unique_lock<mutex> lock(mMutex);
	while (true) {
		if (!mExit) {
			mCondVar.wait(lock);
		}
		lock.unlock();
		while (true) {
			lock.lock();
			if (mQueue.empty()) {
				break;
			}
			else {
				ofs << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}
		if (mExit) {
			break;
		}
	}
}

void logSomeMessages(int id, Logger& logger)
{
	for (int i = 0; i < 10; ++i) {
		stringstream ss;
		ss << "Log entry " << i << " from thread " << id;
		logger.log(ss.str());
	}
}

int main()
{
	Logger logger;
	vector<thread> threads;
	for (int i = 0; i < 10; ++i) {
		threads.emplace_back(logSomeMessages, i, ref(logger));
	}
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}

#include <exception>

class QueueException : public std::exception {
public:
	QueueException(const char* msg, int dataState) : exception(msg) {
		this->dataState = dataState;
	}

	int getDataState() const {
		return dataState;
	}

	enum ErrorsCodes {
		OUT_OF_RANGE = -1,
		QUEUE_IS_EMPTY = 0,
	};

private:
	int dataState;
};
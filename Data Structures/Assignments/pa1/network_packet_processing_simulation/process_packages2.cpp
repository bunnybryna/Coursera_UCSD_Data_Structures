#include <iostream>
#include <queue>
#include <vector>
#include <deque>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}

    Response Process(const Request &request)
	{
		// initialize all fields to 0
		Response responseOne = {0,0};
		// if buffer is not empty
		if (!finish_time_.empty())
		{
			// pop from front all the packets that finished processed
			// last <= arrival_time means this one arrives after last one is processed
			int last=finish_time_.front();
			while ((last <= request.arrival_time))
			{
				finish_time_.pop_front();
				// IMPORTANT!!keep checking if deque is empty!!
				if (finish_time_.empty())
				{
					break;
				}
				last=finish_time_.front();
			}
			//std::cout << "size is " << finish_time_.size() << std::endl;
			if (finish_time_.size() == size_)
			{
				// dropped? yes=>1
				responseOne.dropped = 1;
				responseOne.start_time = 0;
				return responseOne;
			}
			// if there is more room, it has to wait till the last one done
			// here needs a deque data structure to access the one at the tail
			responseOne.dropped = 0;		
			if (!finish_time_.empty())
			{
				int lastFinish  = finish_time_.back();
				responseOne.start_time = lastFinish;
				int finish = lastFinish+request.process_time;
				finish_time_.push_back(finish);				
				//std::cout << "NOT EMPTY: dropped is " << responseOne.dropped << "start is " << responseOne.start_time  << std::endl;				
				return responseOne; 
			}
		}
		// also if after pop front, the deque becomes empty, execution goes here too!
		// if buffer is empty(in two conditions): 
		// 1. the packet is the first one 2. all the packets have been processed
		// the new packet will be processed the moment it arrives
		int finish = request.arrival_time+request.process_time;
		finish_time_.push_back(finish);
		// dropped? no => 0
		responseOne.dropped = 0;
		responseOne.start_time = request.arrival_time;
		//std::cout << "EMPTY: dropped is " << responseOne.dropped << "start is " << responseOne.start_time  << std::endl;
		return responseOne;
	}


private:
    int size_;
    std::deque <int> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}

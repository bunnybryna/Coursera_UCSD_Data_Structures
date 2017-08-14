//https://www.coursera.org/learn/data-structures/discussions/weeks/2/threads/lEkFJefhEeawYBK8xTjgSA
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using std::vector;
using std::cin;
using std::cout;

class CompareDist
{
public:
	bool operator()(std::pair<int, int> n1, std::pair<int, int> n2)
	{
		if (n1.first!=n2.first)
            return n1.first>n2.first;
		else
            return n1.second>n2.second;
	}
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {

    // assigned_workers_.resize(jobs_.size());
    // start_times_.resize(jobs_.size());
	// std::priority_queue<int, vector<int>, std::greater<int> > free_queue;
	// for (int i = 0;i < num_workers_;++i)
	// {
		// free_queue.push(i);
	// }
	//cout << "Popping out elements: ";
	// while(!free_queue.empty())
	// {
		// cout << ' '<< free_queue.top();
		// free_queue.pop();

	// }
	// cout << "\n";
	// std::priority_queue<std::pair<long long,int>, vector<std::pair<long long, int> >, CompareDist> busy_queue;
	// long long start_time = 0;
	// long long finish_time;
	// int workerID;

	// for (int i = 0; i < jobs_.size(); ++i)
	// {
	if there are workers available
	// if (!free_queue.empty())
	// {
		assign this job to the worker
		// workerID = free_queue.top();
		// assigned_workers_[i]=workerID;
		// start_times_[i]=start_time;
		// finish_time = start_time+jobs_[i];
		move this work from free to busy
		// busy_queue.push(std::make_pair(finish_time, workerID));
		// free_queue.pop();
	// }
	// if all the works are occupied
	// free_worker is then empty ?
	// what if available at same time
	// else
	// {
		// workerID = busy_queue.top().second;
		// assigned_workers_[i]=workerID;
		//? maybe start_time += ?
		// start_time = busy_queue.top().first;
		// start_times_[i]=start_time;
		// finish_time = start_time+jobs_[i];
		// busy_queue.push(std::make_pair(finish_time, workerID));
		// busy_queue.pop();
	// }

	// }
	// vector<int> second (4,100);=> four ints with value 100
	// below=> initialize num_workers_ of long long with 0

    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}


    // TODO: replace this code with a faster algorithm.
	// using 2 heaps, one heapfor busy workerssorted by finish time, and one heap for free workers, sorted by their key
	//One queue was used to get the next available thread (ready to process a job) and another priority queue was for storing the jobs finish times. That way i could always keep track of the time to free a thread from processing a job. And also, with that i was able to deal with the case of freeing multiple threads at the same time.
	//By using a priority queue you can use the priority property to sort the queue so you can pop the worker who is ready to work with the lowest index off the queue.
	//I used python 2 and heaps worked for me. The key is that each element of the heap can be a list, so that when the priority is tied, it will use the next element in the list to break the tie. Each node in my heap consisted of a list. The first element was the start time, the second was the initial worker index.

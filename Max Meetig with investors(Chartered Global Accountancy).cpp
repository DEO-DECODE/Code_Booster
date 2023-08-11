
// Max Meetig with investors(Chartered Global Accountancy)
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second != b.second)
	{
		return a.second > b.second;
	}
	else
		return a.first > b.first;
}
int func(vector<int> &firstDay, vector<int> &lastDay)
{
	// investors
	// The greedy part of the solution is that , the owner will try his best to maximize number of meetings
	// So in order to maximize meetings the owner will try to meet investors close to the deadline, so that
	// more slots remain available .
	vector<pair<int, int>> schedule;
	int numMeetings = 0;
	int n = firstDay.size();
	int maxDead = 0;
	for (int i = 0; i < n; ++i)
	{
		schedule.push_back({firstDay[i], lastDay[i]});
		maxDead = max(maxDead, lastDay[i]);
	}
	vector<int> slots(maxDead + 1, -1);
	sort(schedule.begin(), schedule.end(), cmp);
	// for (auto investRout : schedule)
	// {
	// 	cout << investRout.first << " " << investRout.second << endl;
	// }
	for (int i = 0; i < n; ++i)
	{
		int deadline = schedule[i].second;
		int startDay = schedule[i].first;
		// cout << i << endl;
		for (int j = deadline; j >= startDay; --j)
		{
			if (slots[j] == -1)
			{
				slots[j] = 1;
				numMeetings++;
				break;
			}
		}
		// for (auto avail : slots)
		// {
		// 	cout << avail << " ";
		// }
		// cout << endl;
	}
	return numMeetings;
}
int main()
{
	int n;
	cin >> n;
	vector<int> firtDay(n), lastDay(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> firtDay[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> lastDay[i];
	}
	cout << func(firtDay, lastDay);
}

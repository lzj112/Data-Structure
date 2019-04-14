#include <iostream>
#include <list>
#include <string>
#include <algorithm>

struct TimeSegment
{
    uint64_t btime;
    uint64_t etime;
    TimeSegment() : btime(0), etime(0)
    {
    }
    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_)
    {
    }
};

bool compare(TimeSegment tmp1, TimeSegment tmp2) 
{ return tmp1.btime < tmp2.btime; }

inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment)
{
    int lstLen = static_cast<int> (lstTimeSegment.size());

    TimeSegment tmpStamp(nBeginTime, nEndTime);
    lstTimeSegment.push_back(tmpStamp);
    lstTimeSegment.sort(compare);

    std::list<TimeSegment> tmpLst;
    TimeSegment tmpNode(lstTimeSegment.front().btime, 
                        lstTimeSegment.front().etime);
    
    int count = 1;
    for (auto x = lstTimeSegment.begin(); x != lstTimeSegment.end(); x++) 
    {
        count++;
        if (tmpNode.etime >= x->btime) 
        {
            tmpNode.etime = x->etime;
        }
        else 
        {
            tmpLst.push_back(tmpNode);
            tmpNode.btime = x->btime;
            tmpNode.etime = x->etime;
            if (count == lstLen)
            {
                tmpNode.btime = (++x)->btime;
                tmpNode.etime = (++x)->etime;
                tmpLst.push_back(tmpNode);
            }
        }
    }
    std::swap(tmpLst, lstTimeSegment);
}

TimeSegment ParseTimeSegmentString(const std::string &input)
{
    TimeSegment timestamp;
    size_t nPos = input.find("-");
    size_t nLength = input.length();
    if (nPos > 0 && nPos < nLength)
    {
        try
        {
            timestamp.btime = std::stoull(input.substr(0, nPos));
            timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
        }
        catch (...)
        {
            std::cout << "请输入有效数据.\n";
        }
    }
    else
    {
        std::cout << "请输入有效数据.\n";
    }

    return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string &input)
{
    TimeSegment timestamp;
    std::list<TimeSegment> lstTimestamp;
    std::string temp;
    size_t nStartPos = 0;
    size_t nEndPos = input.find(",");
    size_t nLength = input.length();
    while (nEndPos > nStartPos && nEndPos <= nLength)
    {
        temp = input.substr(nStartPos, nEndPos);
        if (temp.size() > 0)
        {
            timestamp = ParseTimeSegmentString(temp);
            lstTimestamp.push_back(timestamp);
        }
        nStartPos = nEndPos + 1;
        nEndPos = input.find(",", nStartPos);
        if (-1 == nEndPos)
        {
            nEndPos = nLength;
        }
    }

    return lstTimestamp;
}

int main(int argc, char *argv[])
{
    std::string input;
    std::cin >> input;
    int nPos = input.find(";");
    std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos)); //这是本地要合并的时间段
    TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size())); //已经同步的时间段

    MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

    for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();)
    {
        std::cout << it->btime << "-" << it->etime;
        if (++it != lstTimestamp.end())
        {
            std::cout << ",";
        }
    }
    std::cout << std::endl;

    return 0;
}
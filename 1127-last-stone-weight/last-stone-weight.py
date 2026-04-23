class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = []
        for i in stones:
            heapq.heappush(pq, -i)
        while(len(pq)>1):
            x = -heapq.heappop(pq)
            y = -heapq.heappop(pq)
            if x!=y:
                heapq.heappush(pq, -(x-y))
        if(len(pq)==1):
            return -pq[0]
        return 0
        
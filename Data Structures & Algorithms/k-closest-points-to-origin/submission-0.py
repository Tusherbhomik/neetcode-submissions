class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxheap = []

        for point in points:
            x = point[0]
            y = point[1]
            distance = x*x+y*y
            heapq.heappush(maxheap,(-distance,point))
            if len(maxheap)>k:
                heapq.heappop(maxheap)
        result = []
        while maxheap:
            result.append(heapq.heappop(maxheap)[1])
        return result
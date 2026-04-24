class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        origin = 0
        countL = 0
        countR = 0
        count = 0
        for i in moves:
            if i=='L':
                countL+=1
            elif i=='R':
                countR+=1
            else:
                count+=1
        if countL>=countR:
            countL+=count
            return (countL - countR)
        else:
            countR+=count
            return countR - countL
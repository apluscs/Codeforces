#!/usr/bin/pypy

maxR = 500
maxC = 500
maxP = 10
maxEl = 1000

maxCost = maxC * maxEl + 1

(nRows,nCols,nPass) = map(int,raw_input().split())

heights = []
isPass = []

for r in xrange(nRows):
    heights.append(map(int,raw_input().split()))
    heights[r].append(0)
    isPass.append([])
    for c in xrange(nCols):
        isPass[r].append(False)

for r in xrange(1,nRows-1):
    for c in xrange(1,nCols-1):
        if heights[r-1][c] > heights[r][c] and heights[r+1][c] > heights[r][c] \
           and heights[r][c+1] != -1 and heights[r][c-1] != -1 and \
           heights[r][c+1] < heights[r][c] and heights[r][c-1] < heights[r][c]:
           isPass[r][c] = True

#print heights
#print isPass

cost = []

for r in xrange(nRows):
    cost.append([])
    for c in xrange(nCols):
        cost[r].append([])
        for p in xrange(maxP+2):
            cost[r][c].append(maxCost)
    cost[r].append([0])
    for p in xrange(maxP+1):
        cost[r][nCols].append(maxCost)

for c in xrange(nCols-1,-1,-1):
    for r in xrange(nRows):
        if heights[r][c] != -1:
            deltaP = 0
            if isPass[r][c]:
                deltaP = 1
            for dir in xrange(3):
                if r+dir-1 >= 0 and r+dir-1 < nRows and heights[r+dir-1][c+1] != -1:
                    for i in xrange(maxP+1):
#                        print r+dir-1,c+1,i,r,c,len(cost[r+dir-1][c+1])
                        dist = cost[r+dir-1][c+1][i]+heights[r][c]
                        if dist < cost[r][c][i+deltaP]:
                            cost[r][c][i+deltaP] = dist

best = maxCost
for r in xrange(nRows):
    if cost[r][0][nPass] < best:
        best = cost[r][0][nPass]

if best == maxCost:
    print "impossible"
else:
    print best

#print cost

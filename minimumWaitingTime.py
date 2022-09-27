def minimumWaitingTime(queries):
    # Write your code here.
    queries.sort()
    waitingTime = previousTime = 0
    for time in queries:
        waitingTime+=previousTime
        previousTime+=time
    return waitingTime

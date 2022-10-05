def twoNumberSum(array, targetSum):
    arrayElements = set(element for element in array)

    for number in array:
        target = targetSum - number
        if target in arrayElements and target != number:
            return [number,target]
    return []


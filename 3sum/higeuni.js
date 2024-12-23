// complexity
// time: O(n^2)
// - sort: O(n log n)
// - for loop: O(n)
// - while loop: O(n)
// space: O(n)
// - sortedNums: O(n)
// - else : O(1)

var threeSum = function(nums) {
  const sortedNums = nums.sort((a, b) => a - b)
  const lengthOfArray = nums.length;
  const answer = [];

  for(let i = 0; i < lengthOfArray; i++ ) {
      if (i > 0 && nums[i] === nums[i - 1]) continue;
      const target = (-1) * sortedNums[i];

      let left = i + 1;
      let right = lengthOfArray - 1;

      while(left < right) {
          const sumOfLeftAndRight = sortedNums[left] + sortedNums[right];
          const diff = sumOfLeftAndRight - target;

          if( diff > 0 ){
              right -= 1;
          } else if ( diff < 0 ){
              left += 1
          } else {
              answer.push([sortedNums[i], sortedNums[left], sortedNums[right]]);
              // 중복되는 부분을 처리하는 과정에서 계속 fail되어 찾아보니 이렇게 해야 통과되었다.
              while(left < right && sortedNums[left] === sortedNums[left + 1]) left ++;
              while(left < right && sortedNums[right] === sortedNums[right - 1]) right --;
              
              left++;
              right--;
          }
      }
  }
  return answer
};


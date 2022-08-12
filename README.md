# Leetcode Solutions

## Merge two sorted lists

### problems faced:

<ol>
<li>
Error:
Line 90: Char 22: runtime error: member access within misaligned address 0x00000000001f for
type 'const ListNode', which requires 8 byte alignment (_Serializer_.cpp)
0x00000000001f: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior _Serializer_.cpp:99:22
</li>

<li>
Realized that my current3 pointer wasn’t getting updated when I used a function to create new
ListNodes dynamically.
</li>

<li>
This is probably because my function was creating a copy of the pointer variables I passed in
the argument. Don’t confuse it with when we pass stuff by reference. When we used to apply
functions to arrays(say) by passing pointers to it, we usually had to edit the information on the
address that the pointer contained and not the address itself, which is why we didn’t come
across any problems. Here, however, we need to modify the value in the pointer itself, and so
we should pass a reference to the pointer variable in the function.
</li>

<li>
Edit: the code DOES work. It’s just that since I was calling it in the main function, the memory
pertaining to the first ListNode of list3, which resided in the stack and not the heap, was getting
freed, making it impossible to access other nodes. Adding a for loop to the function itself, the
code prints the right output
</li>

<li>
The code in leetcode worked (gave the wrong answer but worked) when I initialized the first
node of list3 also in the heap
</li>

<li>
used a function to create nodes. 7ms- faster than 87.80% online submissions. memory usage - 15.1Mb - less than 7.87 % online submissions
</li>

<li>
Things to keep in mind:
Don’t repeat conditions that have already been checked once - redundancy
Pass pointers by reference if you’re playing with the pointer values themselves, and not what is
stored at the address they are pointing to
</li>

</ol>

## Twosum

### first code:

change that needs to be made:
instead of making an entirely new array of nums2, we somehow incorporate increasing each number by the value of least inside the hash function.

### second code:
has time complexity O(n) but is still slower than most online submissions

### third code:
used unordered_map. Code reduced to a single for loop due to fast storage and retrieval of maps and less lines of code. Everything condensed to a single for loop.
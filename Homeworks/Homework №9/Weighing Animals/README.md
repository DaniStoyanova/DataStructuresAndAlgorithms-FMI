# Weighing Animals

Дадени са килограмите на N на брой различни животни, където всеки индекс i отговаря на различно животно, а  са неговите килограми. Даден и критерий за килограми K. Търсим всички тройки животни(индекси), такива че за животните от намерена тройка (x,y,z) е вярно, че Arr[y] = Arr[x] * K, Arr[z] = Arr[y] * K и x<y<z.

### Input Format

Първият ред съдържа две числа N и K. На следващият ред се въвеждат N на брой числа (килограмите Arr[i] на всяко животно i)

### Constraints

1 <= N <= 5 * 10^5 <br>
1 <= K <= 5 * 10^9 <br>
1 <= Arr[i] <= 10^9

### Output Format

Едно число, което съотвества на броят тройки животни

### Sample Input 0

4 3 <br>
1 3 3 9

### Sample Output 0

2

### Explanation 0

От дадените животни можем да сформираме 2 тройки. Едната е от животни (0,1,3) с килограми (1,3,9) 3 = 1 * K, 9 = 3 * K , а другата (0,2,3) с килограми (1,3,9)

### Sample Input 1

6 2 <br>
1 2 4 4 8 16

### Sample Output 1

6

### Explanation 1

Можем да сформираме съответните 6 тройки животни: (0,1,2), (0,1,3), (1,2,4), (1,3,4), (2,4,5), (3,4,5)

### Sample Input 2

5 3 <br>
5 3 1 4 2

### Sample Output 2

0

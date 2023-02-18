# BLG 433E

Storyteller (best in the world) Şule and Glutton Efe study computer engineering at someplace that is technically a university. Since they are in their senior year, they are required to select some courses from the department's elective course offerings. Unfortunately, Efe is not as successful in computer engineering as he is in eating, and he needs the help of Şule while choosing his courses.

Şule recommends Efe to take a computer communications course and claims that every computer engineer should know how the internet and its infrastructure work. However, Efe looks for a course that is easy to get an A and he does not care about what he will learn. That's why Şule decided to create a small routing problem and convince him to take the course by asking some questions. If Efe can answer all of her questions, he will not take this course.

She assumes that,

- There are $n$ data sources that provide data as an integer and $k$ routers that read data from any of the data sources. Data sources are only capable of sending 1 unit of data in a unit of time. After they send data, they remove it and wait until they are requested to send another one. As in real life, each piece of data has different priorities and for this scenario, the priority is determined by the value of the data (bigger data means higher priority).

- Routers can read data from any of the data sources. However, routers have one specific responsibility. They have to read $kth$ important data among all the data waiting at the end of the data sources. For instance, the $5th$ router has to return the $5th$ biggest data value by looking at all data that is ready to be sent. If there exist several data streams with the same data value, the router should read data from a lower-indexed data stream.

<img src="https://contest.ituacm.com/static/images/questions/basar/1.png" width="35%">

Şule asks Efe to implement a program that responds to queries as follows.
- There are $q$ queries to routers.
- Each query contains an integer from $1$ to $k$ that indicates the router number.
- For each query to the $kth$ router, the program should print the value that is read by a $kth$ router.
- If there is not enough data in data streams to return the $kth$ element, the router should return the smallest element.
- If $n < k$, the router should return the $nth$ important data.
- If there is no data in datastreams, the router should return $-1$.

Can you help Efe to implement this program and prevent him getting low grades?

## Input Format

First line contains one integer $n$ which is the number of data streams.

Second line contains one integer $k$ which is the number of routers.

Third line contains one integer $q$ which is the number of queries.

Following $n$ lines consist of space separeted integers which represent data waiting at data stream $i$. First integer is $s \in (0, 1000]$ which is the number of data, following $s$ integers are data of data stream, $data_i \in (0, 10^6]$. Data streams work as FIFO (first in first out) data structure. First read value should be sent out first.

Following $q$ lines contain one integer $k_i$ which is the router that reads data.

## Constraints
$ 1 \leq n \leq 10^4$

$ 1 \leq k \leq 10^4$

$ 1 \leq q \leq 10^4$

## Output Format

Print $q$ lines that each line contains one integer which is the result of corresponding query.

### Sample Input

```
6
3
4
3 3 6 23
2 10 5
3 7 6 1
2 8 3
3 1 2 1
1 2
1
2
2
3
```

### Sample Output

```
10
7
6
3
```

### Sample Explanation

Assume that there are $6$ data streams and $3$ routers and queries as follows $q = [1,2,2,3]$

<img src="https://contest.ituacm.com/static/images/questions/basar/2.png" width="35%">

For $q = 1$, it should return $10$.

<img src="https://contest.ituacm.com/static/images/questions/basar/3.png" width="35%">

For $q = 2$, it should return $7$.

<img src="https://contest.ituacm.com/static/images/questions/basar/4.png" width="35%">

For $q = 2$, it should return $6$.

<img src="https://contest.ituacm.com/static/images/questions/basar/5.png" width="35%">

For $q = 3$, it should return $3$.
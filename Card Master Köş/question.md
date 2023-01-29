# Card Master Köş

Köş shows a couple of his talents as a skilled card player. He plays a game with Bilge:

Bilge is asked to pick a card from a deck of ~n~ cards. To prevent Köş from seeing the card, she hands the selected card back to him with its face turned down. Köş adds the card to his deck and shuffles it. The following operations are listed below.

1. He starts picking the card at the top of the deck and putting it to an appropriate group among ~k~ groups. More formally, let ~c_i~ be the ~i~'th card where ~i\in\left[0,n\right)~  and ~g_j~ be the ~j~'th group. ~c_i~ goes to ~g_j~ where, ~j = i\ \%\ k~ (% operator represents modulo operation). Köş does this for all cards in the deck. He puts the cards onto groups following these rules:
    + All cards will always face upwards.
    + He will place the cards at the top of the group.
    + Groups will be positioned circularly and with their indexes ascending in clockwise direction.

3. Then, Köş asks Bilge to tell him the index of the group her chosen card belongs to. 

4. Next, he constructs a new deck according to Bilge's answer. Assume her answer is ~d~. Starting from the group with index ~\left(d - \frac{k-1}{2}\right) \%\ k~ and moving in clockwise direction, he stacks all groups together with each new group positioned under the stack.

After performing this an infinite number of times, he shows Bilge that the card in the middle of the deck is the one she selected. Bilge is shocked...

However, Köş gets very tired while performing these steps infinitely. At least how many times does he need to iterate in order to put Bilge's chosen card in a position where he can find for sure?

## Input Format

Two integers ~n~ and ~k~ in one line.

- ~n~: the number of cards in a deck.
- ~k~: the number of groups.

## Constraints
- ~n~, ~k~ are odd numbers
- ~1 \leq n \leq 10^{18} ~
- ~1 \leq k \leq n~ such that ~k \vert n~

## Output Format

The minimum number of times Köş needs to perform the same steps in order to find Bilge's card for sure.

If it is not possible for him to find it, print ~-1~.

# Sample Input 1
```
9 3
```
# Sample Output 1
```
2
```
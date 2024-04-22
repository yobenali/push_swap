# Push_swap
**Push_swap** is a sorting algorithm project tackled by students in the 42 Network curriculum. The goal is to sort a stack of numbers using a limited set of instructions, with the aim of minimizing the number of instructions required (ideally no more than 5500 to be considered perfect).
## Introduction

This repository contains the implementation of the Push_swap sorting algorithm project, developed in collaboration with my friend  [@mohamed-souiyeh](https://github.com/mohamed-souiyeh) during our studies at 1337 Coding School, a member of the esteemed 42 Network. Mohamed Souiyeh provided invaluable assistance in understanding and reproducing the algorithm's behavior. This README provides insights into the logic of the algorithms used in Push_swap, as well as acknowledgments for contributions and references to helpful resources.

## Instructions Description
Push_swap utilizes the following set of instructions:

- 'sa': Swap the first 2 elements at the top of stack a.
- 'sb': Swap the first 2 elements at the top of stack b.
- 'ss': Equivalent to 'sa' and 'sb' combined.
- 'pa': Push the first element at the top of stack b to stack a.
- 'pb': Push the first element at the top of stack a to stack b.
- 'ra': Rotate all elements of stack a upwards by 1.
- 'rb': Rotate all elements of stack b upwards by 1.
- 'rr': Equivalent to 'ra' and 'rb' combined.
- 'rra': Rotate all elements of stack a downwards by 1.
- 'rrb': Rotate all elements of stack b downwards by 1.
- 'rrr': Equivalent to 'rra' and 'rrb' combined.

## Algorithm Logic
Push_swap employs a two-stage algorithm:

1. **Pushing numbers from stack a to stack b**: This stage involves efficiently transferring chunks of numbers from stack a to stack b. The algorithm calculates chunk sizes based on the stack size and pushes numbers to stack b while maintaining sorted chunks
2. **Pushing numbers from stack b to stack a**: In this stage, the algorithm optimally moves numbers from stack b back to stack a while ensuring the largest numbers are at the bottom of stack a.

For detailed insights into the algorithm's logic, refer to the [Medium article](https://medium.com/@msouiyeh/not-your-typical-42network-push-swap-cc583f863a90) authored by Mohamed Souiyeh

## Credits and Acknowledgments

Special thanks to Mohamed Souiyeh for his collaboration and insightful contributions to this project. Credits to Jamie Dawson for the Push_swap logo. Additional acknowledgments to helpful peers, including Hamza Hoummadi and Iman Rhesri, for their valuable suggestions and support during the development process.

## Additional Resources

For testing and visualization purposes, consider using the following resources:

- **Tester**: [Push_swap Tester](https://github.com/mohamed-souiyeh/push_swap_tester_2.0)
- **Visualizer**: [ Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

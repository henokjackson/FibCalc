/**
 * Circular Queue Library for Integers
 * 
 * Implements a simple circular queue data structure for storing integer values.
 * The circular queue operates on the principle of a linked list with the first node 
 * linking back to the last node, forming a circle. The queue allows insertion of 
 * data elements and peeking at the elements in the order they were added, following 
 * the FIFO (First In First Out) principle.
 *
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following condition:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM,
 * OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Created By Henok Jackson [Dec. 2024]
 */

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

/**
 * Initialize - Initializes the circular queue with the first element.
 * data: The integer to be inserted into the queue.
 */
void Initialize(int data);

/**
 * Insert - Inserts a new element into the queue.
 * data: The integer value to be inserted.
 */
void Insert(int data);

/**
 * Peek - Returns the next element in the queue without removing it.
 * Returns: The current element.
 */
int Peek(void);

#endif

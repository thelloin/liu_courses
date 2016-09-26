/* Review the following function call:
 *       fun((d, e, f), o, u, ((p, q), r));
 * 
 * The function does not take any parameters with default arguments.
 * - How many parameters does fun have?
 * - Which of d, e, f, o, u, p, q and r are passed to fun?
 * - There are two kind of comman and two kind of paranthesis in this example, which?
 * - What can we say about evaluation order for the different parts of this function call?
 */

/* The nested parenthesis are delimiting comma expressions, so there are
 * four arguments to fun.
 * The result of the comma expression is the last evaluated expression so
 * f, o, u and r will be passed to fun.

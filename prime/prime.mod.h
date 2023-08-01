#ifndef PRIME_H
#define PRIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_def.h"

#module prime

#struct
unsigned char *p;
unsigned long long *pa;
unsigned long long n;
unsigned long long m;
unsigned long long i_max;
unsigned long long n_i;
first;

#init (unsigned long long n, unsigned long long m)
if (!n)
{
	n = 100;
}
if (!m)
{
	m = 100000;
}
p->n = n;
p->m = m;
p->p = malloc(n + 1);
memset(p->p, 0, sizeof(unsigned char) * (n + 1));
p->pa = malloc(sizeof(unsigned long long) * (m + 1));
memset(p->pa, 0, sizeof(unsigned long long) * (m + 1));

#free
if (p->p)
{
	free(p->p);
	p->p = NULL;
}
if (p->pa)
{
	free(p->pa);
	p->pa = NULL;
}

#include "module.h"

FUNCTION_INLINE unsigned long long FUNC(calculate_i)(T *p,
		unsigned long long prime_i);

FUNCTION_INLINE unsigned long long FUNC(first)(T *p)
{
	unsigned char *p1 = NULL;
	unsigned long long n = 0;
	unsigned long long i = 0;
	unsigned long long j = 0;
	unsigned long long m = 0;
	unsigned long long l = 0;
	unsigned long long *pa = NULL;

	if (p)
	{
		p1 = p->p;
		pa = p->pa;
		n = p->n;
		m = p->m;

		memset(p1, 0, sizeof(unsigned char) * (n + 1));
		memset(pa, 0, sizeof(unsigned long long) * (m + 1));

		/*
		   Checks p[i] == 0
		   then from i square crosses out all multiples of i
		 */
		for (i = 2; i * i <= n; i++)
		{
			if (p1[i] == 0)
			{
				for (j = i * i; j <= n; j += i)
				{
					p1[j] = 1;
				}
			}
		}

		/*
		   Copies primes from p to pa
		 */
		for (i = 2; i <= n; i++)
		{
			if (p1[i] == 0)
			{
				pa[l++] = i;
			}
		}
		p->i_max = l;
	}

	return l;
}

FUNCTION_INLINE unsigned long long FUNC(get_i)(T *p,
		unsigned long long i)
{
	unsigned long long pr = 0;

	if (p)
	{
		if (i > 0)
		{
			i--;
			if (!p->is_first)
			{
				FUNC(first)(p);
				if (p->i_max)
				{
					p->is_first = 1;
				}
			}
			if (p->is_first)
			{
				if (i >= p->i_max)
				{
					FUNC(calculate_i)(p, i);
				}
				if (i <= p->i_max)
				{
					pr = p->pa[i];
				}
			}
		}
	}

	return pr;
}

/*
Calculate first i prime
 */
FUNCTION_INLINE unsigned long long FUNC(calculate_i)(T *p,
		unsigned long long prime_i)
{
	unsigned char *p1 = NULL;
	unsigned long long n = 0;
	unsigned long long i = 0;
	unsigned long long j = 0;
	unsigned long long m = 0;
	unsigned long long l = 0;
	unsigned long long o = 0;
	unsigned long long pr = 0;
	unsigned long long *pa = NULL;

	if (p)
	{
		p1 = p->p;
		pa = p->pa;
		n = p->n;
		m = p->m;
		l = p->i_max;
		o = p->n_i;

		m = prime_i > 2 ? prime_i : 3;

		while (l <= m)
		{
			memset(p1, 0, sizeof(unsigned char) * (n + 1));

			o += n;

			for (i = 0; i < l; i++)
			{
				pr = pa[i];
				j = pr * pr;
				if (j < o)
				{
					j = (o / pr) * pr;
					if (j < o)
						j += pr;
				}
				else if (j > n + o)
				{
					break;
				}

/*
Cross out multiples
*/
				for (j = j - o; j <= n; j += pr)
				{
					p1[j] = 1;
				}
			}

			for (i = 1; i <= n; i++)
			{
				if (p1[i] == 0)
				{
					pa[l++] = i + o;
				}
			}
		}

		p->i_max = l;
		p->n_i = o;
	}

	return l;
}

#include "module_undef.h"

#endif	/* PRIME_H */


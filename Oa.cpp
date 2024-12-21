

public
int[] mergetwosortedArray(final int[] A, final int[] B)
{

    int N = A.length;

    int M = B.length;

    int i = 0;

    int j = 0;

    int k = 0;

    int[] ma = new int[N + M];

    while (i < N && j < M)

    {

        if (A[i] < B[j])

        {

            ma[k] = A[i];

            i++;
            k++;
        }

        else
        {

            ma[k] = B[j];

            j++;
            k++;
        }
    }

    while (i < N)

    {

        ma[k] = A[i];

        i++;
        k++;
    }

    while (j < M)

    {

        ma[k] = B[j];

        j++;
        k++;
    }

    return ma;
}


int[] mergesort(int[] A, int lo, int hi)

{

    if (lo == hi)

    {

        int[] ba = new int[1];

        ba[0] = A[lo];

        return ba;
    }

    int mid = (lo + hi) / 2;

    int[] left = mergesort(A, lo, mid);

    int[] right = mergesort(A, mid + 1, hi);

    int[] ans = mergetwosortedArray(left, right);

    return ans;
}
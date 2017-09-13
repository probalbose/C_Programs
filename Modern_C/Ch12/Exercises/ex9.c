double inner_product(const double *a, const double *b, int n) {
    double result=0.0, *pa, *pb;
    for (pa = a, pb = b; pa < a + n; pa++, pb++) 
        result += (*pa * *pb);
    return result;
}

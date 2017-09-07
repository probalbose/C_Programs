void split_date(int day_of_year, int year, int *month, int *day) {
    int i, int months_sum;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0) //Leap year
        days[1] = 29;

    // get month
    months_sum = 0;
    for (i = 0; i < 12; i++) {
        if (day_of_year < months_sum) {
            *month = i + 1;
            break;
        } else
            months_sum += days[i];
    }

    // get day
    months_sum = 0;
    for (i = 0; i < 12; i++) {
        if (months_sum + days[i] > day_of_year) {
            *day = day_of_year - months_sum;
            break;
        else
            months_sum += days[i];
    }
}

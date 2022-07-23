
char * name_of_month(int n){
    static char *name[] = {
        "Illegal month", "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void about_devs(void);//list of developers

int hour, minute, second;//manual variables
int hours, minutes, seconds;//alarm variables

void display_time(void);
void display_clock_options(void);

//updating the clock manually
void Time_update(void);
void manual_update(void);
void get_hours_manual(void);
void get_minutes_manual(void);
void get_seconds_manual(void);
void display_manual_time(void);

//setting the alarm
void setting_alarm_confirm(void);//confirm user choice
void alarm_setting(void);//interface for setting alarm
void get_hours(void);
void get_minutes(void);
void get_seconds(void);

int main()
{
    system("color 3F");
    display_time();
    return 0;
}

void display_time(void){
    system("cls"); // Clear once at start
    display_clock_options();
    printf("\n\tCurrent Time: "); // Print this once
    
    while(1){
        // Use carriage return to update in place
        printf("\r"); // Return to start of line
        
        time_t duration;
        duration = time(NULL);
        struct tm *current;
        current = localtime(&duration);
        
        char buffer[10];
        strftime(buffer, 10, "%H:%M:%S", current);
        
        printf("\tCurrent Time: %s", buffer);
        if(current->tm_hour >= 12 && current->tm_hour < 24){
            printf(" PM   "); // Extra spaces to clear previous text
        }
        else printf(" AM   ");
        
        fflush(stdout); // Force output to show immediately

        // ALARM RING
        if(hours == current->tm_hour && minutes == current->tm_min && seconds == current->tm_sec){
            system("cls");
            int i;
            for(i = 1; i < 300; i++){
                printf("\n\t\tTHE ALARM IS RINGING...\n");
                printf("___________________________________________________________________________________________\n\n");
                printf("\tPress any key to Dismiss\n");
                
                Beep(1000, 500);
                system("cls");
                
                if(_kbhit()){
                    system("cls");
                    display_clock_options();
                    printf("\n\tCurrent Time: ");
                    break;
                }
            }
        }

        if (_kbhit()) {
            char key = _getch();
            if (key == '1') { 
                Time_update();
                break;
            } else if (key == '2') {
                setting_alarm_confirm();
                system("cls");
                display_clock_options();
                printf("\n\tCurrent Time: ");
            } else if (key == '3') {
                YES_NO_AUTO:	
                system("cls");
                char yn;
                printf("\nARE YOU SURE YOU WANT TO EXIT CLOCK?\n\n");
                printf("Press Y for YES/ N for NO: ");
                yn = getche();
                 
                switch(yn){
                    case 'y':
                    case 'Y':
                        exit(1);
                        break;
                    case 'n':
                    case 'N':
                        system("cls");
                        display_clock_options();
                        printf("\n\tCurrent Time: ");
                        break;
                    default:
                        system("cls");
                        goto YES_NO_AUTO;
                }
            } else if (key == '4') {
                system("cls");
                about_devs();
                printf("\n\nPress any key to continue...");
                getch();
                system("cls");
                display_clock_options();
                printf("\n\tCurrent Time: ");
            }
        }
        sleep(1);
    }
}

void display_clock_options(void){
    printf("\t*******DIGITAL CLOCK SYSTEM*******\n");
    printf("___________________________________________________________________________________________\n\n");
    printf(" Clock Options\n\n");
    printf(" 1. Reset Time\n");
    printf(" 2. Set Alarm\n");
    printf(" 3. Exit Clock\n");
    printf(" 4. About Developers\n");
}

void Time_update(void){
    char choice;
    CHOOSE_AGAIN:
    system("cls");
    printf("CHOOSE ONE OF THE OPTION BELOW\n\n");
    printf("___________________________________________________________________________________________\n");
    printf("\n Press 1 for manual update\n");
    printf(" Press 2 for automatic update\n");
    printf(" Press 0 to go back to clock\n");
    printf("\n Enter choice: ");

    choice = getche();
    system("cls");
    
    switch(choice){
        case '1':
            manual_update();
            break;
        case '2':
        case '0':
            display_time();
            break;
        default:
            goto CHOOSE_AGAIN;
    }
}

void manual_update(void){
    system("cls");
    printf("\t*****MANUAL TIME UPDATE*******\n");
    printf("___________________________________________________________________________________________\n");
    
    printf(" Enter hour (0-23): ");
    get_hours_manual();
    
    printf(" Enter minutes (0-59): ");
    get_minutes_manual();
    
    printf(" Enter seconds (0-59): ");
    get_seconds_manual();
    
    display_manual_time();
}

void get_hours_manual(void){
    int hr_status;
    system("cls");
    printf("*****MANUAL TIME UPDATE*******\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("Enter hours: ");
    HR:
    HR_2:
    hr_status = scanf("%d", &hour);
    getchar();
    if(hour < 0 || hour > 23){
        printf("\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("Please enter HOURS in a range of 0 to 23: ");
        goto HR;	
    }
    else if (hr_status == 0){
        printf("\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("Please enter HOURS in numbers in a range of 0 to 23: ");
        goto HR_2;
    }
}

void get_minutes_manual(void){
    int min_status;
    system("cls");
    printf("*****MANUAL TIME UPDATE*******\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("\nEnter minutes: ");
    MINS:
    MIN_2:
    min_status = scanf("%d", &minute);
    getchar();
    if(minute < 0 || minute > 59){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter MINUTES in a range of 0 to 59: ");
        goto MINS;	
    }
    else if (min_status == 0){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter MINUTES in numbers in a range of 0 to 59: ");
        goto MIN_2;
    }
}

void get_seconds_manual(void){
    int sec_status;
    system("cls");
    printf("*****MANUAL TIME UPDATE*******\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("\nEnter seconds: ");
    SEC:
    SEC_2:
    sec_status = scanf("%d", &second);
    getchar();
    if(second < 0 || second > 59){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter SECONDS in a range of 0 to 59: ");
        goto SEC;
    }
    else if (sec_status == 0){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("*****MANUAL TIME UPDATE*******\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter SECONDS in numbers in a range of 0 to 59: ");
        goto SEC_2;
    }
}

void display_manual_time(void){
    system("cls");
    display_clock_options();
    printf("\n\t\t\tTIME: ");
    
    while(1){
        printf("\r"); // Use carriage return to update in place
        printf("\t\t\tTIME: %02d:%02d:%02d", hour, minute, second);
        if(hour >= 12 && hour < 24){
            printf(" PM   ");
        }
        else printf(" AM   ");
        
        fflush(stdout);

        // ALARM RING
        if(hours == hour && minutes == minute && seconds == second){
            system("cls");
            int i;
            for(i = 1; i < 300; i++){
                printf("\n\t\tTHE ALARM IS RINGING...\n");
                printf("___________________________________________________________________________________________\n\n");
                printf("\tPress any key to Dismiss\n");
                
                Beep(1000, 500);
                system("cls");
                
                if(_kbhit()){
                    system("cls");
                    display_clock_options();
                    printf("\n\t\t\tTIME: ");
                    break;
                }
            }
            minute += 2;
        }
        
        second++;
        
        if(kbhit()){
            char ch = getch();
            switch(ch){
                case '1':
                    system("cls");
                    Time_update();
                    break;
                case '2':
                    system("cls");
                    setting_alarm_confirm();
                    system("cls");
                    display_clock_options();
                    printf("\n\t\t\tTIME: ");
                    break;
                case '3':
                    YES_NO:
                    system("cls");
                    char yn;
                    printf("\nARE YOU SURE YOU WANT TO EXIT CLOCK?\n\n");
                    printf("Press Y for YES/ N for NO: ");
                    yn = getche();
                     
                    switch(yn){
                        case 'y':
                        case 'Y':
                            exit(1);
                            break;
                        case 'n':
                        case 'N':
                            system("cls");
                            display_clock_options();
                            printf("\n\t\t\tTIME: ");
                            break;
                        default:
                            system("cls");
                            goto YES_NO;
                    }
                    break;
            }
        }

        if(second == 60){
            second = 0;
            minute++;
            if(minute == 60){
                minute = 0;
                hour++;
                if(hour == 24){
                    hour = 0;
                    minute = 0;
                    second = 0;
                }
            }
        }
        sleep(1);
    }
}

void alarm_setting(void){
    system("cls");
    printf("******SET YOUR ALARM*****\n");
    printf("___________________________________________________________________________________________\n\n");
    printf("Enter hours: ");
    get_hours();
    
    printf("Enter minutes: ");
    get_minutes();
    
    printf("Enter seconds: ");
    get_seconds();
    
    printf("\n\nAlarm set successfully!\n");
    Sleep(2000);
}

void setting_alarm_confirm(void){
    char choice;
    CHOOSE_AGAIN:
    system("cls");
    printf("SETTING ALARM\n");
    printf("___________________________________________________________________________________________\n\n");
    printf("1. Set alarm\n");
    printf("2. Cancel setting alarm\n");
    
    choice = getch();
    switch(choice){
        case '1':
            alarm_setting();		
            break;
        case '2':
            break;
        default:
            printf("\nWrong input! Press 1 or 2\n");
            Sleep(1500);
            goto CHOOSE_AGAIN;
    }
}

void get_hours(void){
    int hr_status;
    system("cls");
    printf("******SETTING ALARM*******\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("Enter hours: ");
    HR:
    HR_2:
    hr_status = scanf("%d", &hours);
    getchar();
    if(hours < 0 || hours > 23){
        printf("\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("******SETTING ALARM*****\n");
        printf("___________________________________________________________________________________________\n");
        printf("Please enter HOURS in a range of 0 to 23: ");
        goto HR;	
    }
    else if (hr_status == 0){
        printf("\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("SETTING ALARM\n");
        printf("___________________________________________________________________________________________\n");
        printf("Please enter HOURS in numbers in a range of 0 to 23: ");
        goto HR_2;
    }
}

void get_minutes(void){
    int min_status;
    system("cls");
    printf("SETTING ALARM\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("\nEnter minutes: ");
    MINS:
    MIN_2:
    min_status = scanf("%d", &minutes);
    getchar();
    if(minutes < 0 || minutes > 59){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("SETTING ALARM\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter MINUTES in a range of 0 to 59: ");
        goto MINS;	
    }
    else if (min_status == 0){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("SETTING ALARM\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter MINUTES in numbers in a range of 0 to 59: ");
        goto MIN_2;
    }
}

void get_seconds(void){
    int sec_status;
    system("cls");
    printf("SETTING ALARM\n");
    printf("___________________________________________________________________________________________\n");
    
    printf("\nEnter seconds: ");
    SEC:
    SEC_2:
    sec_status = scanf("%d", &seconds);
    getchar();
    if(seconds < 0 || seconds > 59){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("SETTING ALARM\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter SECONDS in a range of 0 to 59: ");
        goto SEC;
    }
    else if (sec_status == 0){
        printf("\n\nINVALID INPUT\n");
        Sleep(1300);
        system("cls");
        printf("SETTING ALARM\n");
        printf("___________________________________________________________________________________________\n");
        printf("\nPlease enter SECONDS in numbers in a range of 0 to 59: ");
        goto SEC_2;
    }
}

void about_devs(void){
    printf("\n   BACHELOR OF SCIENCE IN INFORMATION AND COMMUNICATION TECHNOLOGY\n");
    printf("___________________________________________________________________________________________\n\n");
    printf("Developed by:\n");
    printf("- Developer 1\n");
    printf("- Developer 2\n");
    printf("- Developer 3\n\n");
    printf("Press any key to go back to clock");
}
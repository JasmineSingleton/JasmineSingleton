/*
Name: Jasmine Singleton
Course: SCIS 346
Date: 10/4/23
Purpose: The purpose of this program is to find the roots
and handle complex roots from the quadratic equation.

*/

import java.util.Random;
import java.util.Scanner;

public class GUESSINGGAME{

    public static void main(String[] args) {
        playGame(); //calling game function
}

    public static void playGame() {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);

        int correctNum = random.nextInt(101); //setting random number range
        int count = 1;

        System.out.println("\nHello! You have 10 tries to guess the lucky number!\n");

        while (count <= 10) { //looping until they run out of guesses or win
            System.out.print(count + ". Enter your guess: ");
            int guess = scanner.nextInt();

            if (guess == correctNum){
                System.out.println("\nGreat job! You win! The lucky number is " + correctNum); //displaying that the user wins and the numeber
                break;
            } else if (count == 10){
                System.out.println("-----------------------------------------------");
                System.out.println("Well, I guess you tried?");
                System.out.println("The lucky number was " + correctNum); //displaying the correct number
                System.out.println("-----------------------------------------------");
            } else if (guess > correctNum){ //displaying if the guess is too high
                System.out.println("TOO HIGH");
            } else if (guess < correctNum){ //displaying if the guess is too low
                System.out.println("TOO LOW");
            }

            if (count == 5){ //displaying that the user has 5 guesses left
                System.out.println("-----------------------------------------------");
                System.out.println("I'm getting second-hand embarrassment...");
                System.out.println("...from how long it is taking you to guess correctly...");
                System.out.println("You only have 5 guesses left.");
                System.out.println("-----------------------------------------------");
            
            } else if (count == 9){ //displaying that the user has one guess left
                System.out.println("-----------------------------------------------");
                System.out.println("Um... maybe you should just stop trying...");
                System.out.println("One guess left.");
                System.out.println("-----------------------------------------------");
            }

            count++; //updating counter
        }

        System.out.print("Enter 'yes' to play again or 'no' to quit: ");
        String playAgain = scanner.next().toLowerCase();


        //checking to see if user wants to play again
        if (playAgain == "yes"){
            playGame();
        } else {
            System.out.println("Thanks for playing :)"); //displaying goodbye message
        }

        scanner.close();
    }
}

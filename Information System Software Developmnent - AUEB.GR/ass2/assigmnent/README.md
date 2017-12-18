Υπολογισμός Συντομότερων Μονοπατιών και Διαμέτρου Γράφου
=========================================================

Σκοπός της εργασίας είναι η συγγραφή προγραμμάτων σε γλώσσα Java για
τον υπολογισμό συντομότερων μονοπατιών και διαμέτρου ενός γράφου.

Η εργασία είναι προσωπική.

Κάθε φοιτητής θα εργαστεί στο προσωπικό του αποθετήριο στο GitHub. Για
να αξιολογηθεί μια εργασία θα πρέπει να πληροί τις παρακάτω
προϋποθέσεις:

1. Όλη η εργασία θα πρέπει να βρίσκεται σε έναν κατάλογο
  ``assignment-2`` μέσα στο αποθετήριο του φοιτητή.

2. Ο πηγαίος κώδικας του προγράμματος που θα γραφτεί θα πρέπει να βρίσκεται
  σε έναν υποκατάλογο ``src`` του καταλόγου ``assignment-2``.

3. Ο μεταγλωττισμένος κώδικας του προγράμματος που θα γραφτεί θα
  πρέπει να βρίσκεται σε έναν υποκατάλογο ``bin`` του καταλόγου
  ``assignment-2``. Έτσι, αν το αποθετήριο του φοιτητή είναι το
  ``example-repo``, η δομή των καταλόγων θα είναι:
    ```
    example-repo
        assignment-2
            src
            bin
    ```
4. Το πρόγραμμα θα πρέπει να έχει όνομα ``Graph``.

5. Το πρόγραμμα θα πρέπει να εκτελείται με τους παρακάτω τρόπους:
    #### Συντομότερο μονοπάτι από συγκεκριμένο κόμβο
    ``` 
    java Graph [-u] -s start example_graph.txt
    ```

    Στην περίπτωση αυτή, το πρόγραμμα θα παράγει στην έξοδο το αποτέλεσμα
    της εκτέλεσης του αλγορίθμου του Dijkstra στο γράφο που περιέχεται
    στο αρχείο ``example_graph.txt`` με κόμβο εκκίνησης τον κόμβο start.
    Αν δίνεται η παράμετρος ``-u`` τότε ο γράφος που περιέχεται στο αρχείο
    είναι μη κατευθυνόμενος.

    Για παράδειγμα, αν το πρόγραμμα κληθεί ως εξής:
    ```
    java Graph -s 0 traffic.txt
    ```
    η έξοδος θα πρέπει είναι της μορφής:
    ```
    Predecessor matrix
    [-1, 0, 1, 2, 0, 4, 2, 6, 4, 10, 6, 10, 13, 14, 10, 11]
    Distance matrix
    [0, 3, 4, 8, 5, 8, 6, 14, 12, 13, 9, 15, 17, 14, 12, 18]
    ```
    όπου ο πρώτος πίνακας δείχνει για κάθε κόμβο τον κόμβο που
    προηγείται στο συντομότερο μονομάτι από τον κόμβο 0, και ο δεύτερος
    πίνακας δείχνει το κόστος του συντομότερου μονοπατιού. Αν ένας κόμβος δεν
    έχει προηγούμενο, τότε ως προηγούμενος θα εμφανίζεται ο κόμβος -1.

    Αν το αρχείο είναι μη κατευθυνόμενο, η αντίστοιχη εντολή θα είναι:
    ```
    java Graph -u -s 0 traffic_u.txt
    ```

    #### Ζεύγη συντομότερων μονοπατιών
    ``` 
    java Graph [-u] -a example_graph.txt
    ```
    Στην περίπτωση αυτή, το πρόγραμμα θα παράγει στην έξοδο το αποτέλεσμα
    της εκτέλεσης του αλγορίθμου εύρεσης όλων των ζευγών συντομότερων
    μονοπατιών στο γράφο που περιέχεται στο αρχείο ``example_graph.txt``.
    Αν δίνεται η παράμετρος ``-u`` τότε ο γράφος που περιέχεται στο αρχείο
    είναι μη κατευθυνόμενος.

    Για παράδειγμα, αν το πρόγραμμα κληθεί ως εξής:
    ```
    java Graph -a traffic.txt
    ```
    Η έξοδος θα πρέπει να είναι της μορφής:
     ```
     Predecessor matrix
     [-1, 0, 1, 2, 0, 4, 2, 6, 4, 10, 6, 10, 13, 14, 10, 11]
     [1, -1, 1, 2, 0, 6, 2, 6, 4, 10, 6, 10, 13, 14, 10, 11]
     [1, 2, -1, 2, 0, 6, 2, 6, 4, 10, 6, 10, 13, 14, 10, 11]
     [1, 2, 3, -1, 0, 6, 2, 3, 4, 10, 6, 7, 13, 14, 10, 11]
     [4, 0, 1, 2, -1, 4, 5, 6, 4, 5, 6, 10, 8, 9, 10, 11]
     [4, 2, 6, 2, 5, -1, 5, 6, 4, 5, 6, 10, 8, 9, 10, 11]
     [1, 2, 6, 2, 5, 6, -1, 6, 9, 10, 6, 10, 13, 14, 10, 11]
     [1, 2, 3, 7, 5, 6, 7, -1, 9, 10, 11, 7, 13, 14, 10, 11]
     [4, 0, 1, 2, 8, 4, 5, 11, -1, 8, 9, 10, 8, 12, 13, 14]
     [1, 2, 6, 2, 5, 9, 10, 11, 9, -1, 9, 10, 13, 9, 13, 14]
     [1, 2, 6, 2, 5, 6, 10, 11, 9, 10, -1, 10, 13, 14, 10, 11]
     [1, 2, 6, 7, 5, 6, 10, 11, 9, 10, 11, -1, 13, 14, 10, 11]
     [1, 2, 6, 2, 8, 9, 10, 11, 12, 13, 14, 10, -1, 12, 13, 14]
     [1, 2, 6, 2, 8, 9, 10, 11, 12, 13, 14, 10, 13, -1, 13, 14]
     [1, 2, 6, 2, 5, 6, 10, 11, 12, 13, 14, 10, 13, 14, -1, 14]
     [1, 2, 6, 7, 5, 6, 10, 11, 12, 13, 11, 15, 13, 14, 15, -1]
     Distance matrix
     [0, 3, 4, 8, 5, 8, 6, 14, 12, 13, 9, 15, 17, 14, 12, 18]
     [3, 0, 1, 5, 8, 8, 3, 11, 15, 10, 6, 12, 14, 11, 9, 15]
     [4, 1, 0, 4, 9, 7, 2, 10, 16, 9, 5, 11, 13, 10, 8, 14]
     [8, 5, 4, 0, 13, 11, 6, 6, 20, 13, 9, 8, 17, 14, 12, 11]
     [5, 8, 9, 13, 0, 3, 8, 16, 7, 12, 11, 17, 13, 16, 14, 20]
     [8, 8, 7, 11, 3, 0, 5, 13, 10, 9, 8, 14, 16, 13, 11, 17]
     [6, 3, 2, 6, 8, 5, 0, 8, 15, 7, 3, 9, 11, 8, 6, 12]
     [14, 11, 10, 6, 16, 13, 8, 0, 20, 12, 8, 2, 16, 13, 11, 5]
     [12, 15, 16, 20, 7, 10, 15, 20, 0, 8, 12, 18, 6, 9, 11, 18]
     [13, 10, 9, 13, 12, 9, 7, 12, 8, 0, 4, 10, 7, 4, 6, 13]
     [9, 6, 5, 9, 11, 8, 3, 8, 12, 4, 0, 6, 8, 5, 3, 9]
     [15, 12, 11, 8, 17, 14, 9, 2, 18, 10, 6, 0, 14, 11, 9, 3]
     [17, 14, 13, 17, 13, 16, 11, 16, 6, 7, 8, 14, 0, 3, 5, 12]
     [14, 11, 10, 14, 16, 13, 8, 13, 9, 4, 5, 11, 3, 0, 2, 9]
     [12, 9, 8, 12, 14, 11, 6, 11, 11, 6, 3, 9, 5, 2, 0, 7]
     [18, 15, 14, 11, 20, 17, 12, 5, 18, 13, 9, 3, 12, 9, 7, 0]
     ```

    #### Διάμετρος γράφου
    ``` 
    java Graph [-u] -d traffic.txt
    ```
    Τότε το πρόγραμμα θα εμφανίζει στην έξοδο τη διάμετρο του γράφου.
    Αν δίνεται η παράμετρος ``-u`` τότε ο γράφος που περιέχεται στο αρχείο
    είναι μη κατευθυνόμενος.

    Για παράδειγμα αν το πρόγραμμα κληθεί ως εξής:
    ```
    java Graph -d traffic.txt
    ```
    η έξοδος θα πρέπει να είναι της μορφής:
    ```
    20
    ```
    
6. Οι γράφοι που θα δίνονται στον πρόγραμμα θα βρίσκονται σε αρχεία κειμένου
   της μορφής:
   ```
   0 1 10
   0 3 5
   1 2 1
   1 3 2
   2 4 4
   3 1 3
   3 2 9
   3 4 2
   4 2 6
   4 1 7
   ```
   ή της μορφής:
   ```
   0 1
   0 3
   1 2
   1 3
   2 4
   3 1
   3 2
   3 4
   4 2
   4 1
   ```
   Στην πρώτη περίπτωση, η κάθε γραμμή περιγράφει ένα σύνδεσμο από τον κόμβο
   που αντιστοιχεί στο πρώτο πεδίο στον κόμβο που αντιστοιχεί στο δεύτερο
   πεδίο. Το τρίτο πεδίο είναι το βάρος του συνδέσμου. Στη δεύτερη περίπτωση
   το βάρος θεωρείται ότι είναι ίσο με 1. Οι κόμβοι θα είναι αριθμημένοι
   σειριακά, ξεκινώντας από το 0.
   
Αν μια εργασία δεν ικανοποιεί τις παραπάνω απαιτήσεις ***δεν θα είναι
δυνατή η αξιολόγησή της***. Επιβεβαιώστε λοιπόν ότι πράγματι το
πρόγραμμά σας μπορεί να κληθεί ***ακριβώς*** με τις εντολές που δίνονται
παραπάνω, και ότι παράγει ***ακριβώς*** την έξοδο που περιγράφεται.

Προσέξτε ότι σύμφωνα με τα παραπάνω το πρόγραμμά σας δεν θα πρέπει από μόνο
του να σώζει τα αποτελέσματα σε κάποιο αρχείο, απλώς να τα εμφανίζει στην
έξοδο. Αν θέλετε να τα σώσετε σε αρχείο θα πρέπει να το καλείτε αναλόγως:
    ``` 
    java Graph -a traffic.txt > output.txt
    ```

Για να ελέγξετε το πρόγραμμά σας μπορείτε να χρησιμοποιήσετε τα αρχεία:

* [clrs.txt](https://github.com/dmst-algorithms-course/assigmnent-2/blob/master/clrs.txt)
  Κατευθυνόμενος γράφος

* [traffic.txt](https://github.com/dmst-algorithms-course/assigmnent-2/blob/master/traffic.txt)
  Κατευθυνόμενος γράφος

* [traffic_u.txt](https://github.com/dmst-algorithms-course/assigmnent-2/blob/master/traffic_u.txt)
  Μη κατευθυνόμενος γράφος

* [facebook_combined_u.txt.zip](https://github.com/dmst-algorithms-course/assigmnent-2/blob/master/facebook_compined.txt.zip)
  Μη κατευθυνόμενος γράφος με στοιχεία από τις λίστες φίλων χρηστών του
  Facebook. Πηγή: J. McAuley and J. Leskovec.
  Learning to Discover Social Circles in Ego Networks. NIPS, 2012.
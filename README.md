# TDSC23-VCQ (Unofficial version)
This code is for paper "Forward Private Verifiable Dynamic Searchable Symmetric Encryption with Efficient Conjunctive Query". 


## Dataset

* Download Enron data wget https://www.cs.cmu.edu/~./enron/enron_mail_20150507.tar.gz or axel -n {nthreads}  https://www.cs.cmu.edu/~./enron/enron_mail_20150507.tar.gz

* unzip it with tar -xvf {eron_file_name} , use ls -lR|grep "^-"|wc -l can show the total files in the datasets.

* mkdir Enron_datasets and move the script 'renameEnronDir.sh' to the same dir where 'Enron_datasets' folder and unzip Enron data 'maildir' resides.

* run the scripts bash renameEnronDir.sh maildir which will copy the 'maildir' into the 'Enron_datasets' folder with renamed name of each file. This will help the code to easily transfer the mail into key-valu pair in parallel mode.

* move 'extractEnronLinked.py' to the same dir where 'Enron_datasets' folder resides and run mkdir Enron_linkedList && python extractEnronLinkedList.py {nthreads}, then the linked list will be stored in folder 'Enron_linkedList'.

* move 'extractEnronInvertedList.py' to the same dir where 'Enron_linkedList' folder resides and run mkdir Enron_invertedlinkedList && python extractEnronInvertedList.py {nthreads}, then the inverted linked list will be stored in folder 'Enron_invertedlinkedList'.

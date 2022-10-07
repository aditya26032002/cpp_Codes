text = "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG"
word = text.split()
width = 13

print("1. Left justify\n2. Right justify\n3. Center justify\nInput your choice: ")
choice = int(input())
length = 0
spaces = 0
sentence = ""
strfin = ""

if(choice == 1):
  for i in range(len(word)):
    if(length + len(word[i]) < width):
      length += len(word[i]) + 1
      sentence += word[i] + " "
    elif(length + len(word[i]) == width):
      length += len(word[i])
      sentence += word[i]

    if(i+1 < len(word)):
      if(length + len(word[i+1]) > width):
        spaces = width - length
        for i in range(spaces):
          strfin += "_"

        strfin += sentence
        print(strfin)
        length = spaces = 0
        sentence = ""
        strfin = ""

    else:
      spaces = width - length
      for i in range(spaces):
        strfin += "_"

      strfin += sentence
      print(strfin)
      length = spaces = 0
      sentence = ""
      strfin = ""
      

elif(choice == 2):
  for i in range(len(word)):
    if(length + len(word[i]) < width):
      length += len(word[i]) + 1
      sentence += word[i] + " "
    elif(length + len(word[i]) == width):
      length += len(word[i])
      sentence += word[i]

    if(i+1 < len(word)):
      if(length + len(word[i+1]) > 13):
        spaces = width - length
        strfin += sentence

        for i in range(spaces):
          strfin += "_"

        print(strfin)
        length = spaces = 0
        sentence = ""
        strfin = ""

    else:
      spaces = width - length
      strfin += sentence

      for i in range(spaces):
        strfin += "_"

      print(strfin)
      length = spaces = 0
      sentence = ""
      strfin = ""

elif(choice == 3):
  for i in range(len(word)):
    if(length + len(word[i]) < width):
      length += len(word[i]) + 1
      sentence += word[i] + " "
    elif(length + len(word[i]) == width):
      length += len(word[i])
      sentence += word[i]

    if(i+1 < len(word)):
      if(length + len(word[i+1]) > width):
        spaces = width - length
        for i in range(spaces):
          strfin += "_"

        strfin += sentence
        print(strfin)
        length = spaces = 0
        sentence = ""
        strfin = ""

    else:
      spaces = width - length
      for i in range(int(spaces/2)):
        strfin += "_"

      strfin += sentence

      for i in range(int(spaces/2)):
        strfin += "_"

      print(strfin)
      length = spaces = 0
      sentence = ""
      strfin = ""

else:
  print("Wrong choice")
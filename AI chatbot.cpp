import datetime
import webbrowser

knowledge_base = {
    "hello": "Hello! How can I assist you today?",
    "hi": "Hi there! Need any help?",
    "bye": "Goodbye! Have a great day.",
    "exit": "Exiting chat. See you soon!",
    "advice": "Keep learning and stay curious!",
    "help with academics": "Sure! I can help with programming, math, or electronics.",
    "project ideas": "Try Hospital Record Management, Smart Attendance System, or a Voice-Controlled Robot."
}

recipe_base = {
    "maggi": "1. Boil 1.5 cups of water\n2. Add Maggi noodles and tastemaker\n3. Cook for 2 minutes and enjoy!",
    "tea": "1. Boil 1 cup of water\n2. Add tea powder and sugar\n3. Add milk and boil\n4. Strain and serve hot.",
    "pasta": "1. Boil pasta\n2. Saute veggies\n3. Add pasta sauce\n4. Mix pasta and cook for 2-3 mins.",
    "rice": "1. Rinse rice\n2. Add 2x water\n3. Cook on medium flame or use rice cooker."
}

def save_to_chat_log(user_input, bot_reply):
    with open("chatlog.txt", "a") as log_file:
        log_file.write(f"You: {user_input}\n")
        log_file.write(f"Bot: {bot_reply}\n\n")

def show_time():
    now = datetime.datetime.now()
    print("Current time:", now.strftime("%Y-%m-%d %H:%M:%S"))

def calculator():
    try:
        expr = input("Enter expression (e.g. 5 + 2): ")
        result = eval(expr)
        print("Result:", result)
    except Exception as e:
        print("Error:", str(e))

def create_note():
    filename = input("Enter filename (e.g. note.txt): ")
    content = input("Enter note content: ")
    with open(filename, "w") as file:
        file.write(content)
    print(f"Note saved as {filename}")

def read_note():
    filename = input("Enter filename to read: ")
    try:
        with open(filename, "r") as file:
            print("Content of", filename)
            print(file.read())
    except FileNotFoundError:
        print("File not found.")

def joke_interaction():
    answer = input("Bot: Who is the brother of an ant?\nYou: ").strip().lower()
    if answer == "antenna":
        print("Bot: Correct! You're smart! 😄")
    elif answer == "give answer":
        print("Bot: The answer is 'Antenna'! (Ant - enna 😄)")
    else:
        print("Bot: Hmm, not quite. Try again or type 'give answer'!")

def ask_quiz():
    answer = input("Bot: What is the capital of France?\nYou: ").strip().lower()
    if answer == "paris":
        print("Bot: Correct! 🎉")
    else:
        print("Bot: Oops! It's Paris.")

def find_best_match(user_input):
    user_input = user_input.lower()

    if "open google" in user_input:
        webbrowser.open("https://www.google.com")
        return "Opening Google..."
    elif "open youtube" in user_input:
        webbrowser.open("https://www.youtube.com")
        return "Opening YouTube..."
    elif "open college" in user_input:
        webbrowser.open("https://ceg.annauniv.edu")
        return "Opening college site..."
    elif "calculator" in user_input:
        calculator()
        return ""
    elif "create note" in user_input:
        create_note()
        return ""
    elif "read note" in user_input:
        read_note()
        return ""
    elif "time" in user_input:
        show_time()
        return ""
    elif "joke" in user_input:
        joke_interaction()
        return ""
    elif "quiz" in user_input:
        ask_quiz()
        return ""
    elif "recipe for" in user_input:
        for dish, recipe in recipe_base.items():
            if dish in user_input:
                return f"Here's the recipe for {dish}:\n{recipe}"
        return "Sorry, I don't have the recipe for that dish yet."
    else:
        for key in knowledge_base:
            if key in user_input:
                return knowledge_base[key]
    return "I'm not sure how to respond to that."

def run_chatbot():
    print("=== Welcome to Python ChatBot ===")
    print("Type 'exit' or 'bye' to quit.\n")
    while True:
        user_input = input("You: ").strip()
        if user_input.lower() in ["exit", "bye"]:
            print("Bot:", knowledge_base["bye"])
            save_to_chat_log(user_input, knowledge_base["bye"])
            break
        reply = find_best_match(user_input)
        if reply:
            print("Bot:", reply)
            save_to_chat_log(user_input, reply)

run_chatbot()

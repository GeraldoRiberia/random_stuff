import os
import shutil
from cryptography.fernet import Fernet, InvalidToken

def generate_key():
    return Fernet.generate_key()

def encrypt_file(key, file_path):
    with open(file_path, 'rb') as f:
        data = f.read()

    cipher = Fernet(key)
    encrypted_data = cipher.encrypt(data)

    with open(file_path + '.encrypted', 'wb') as f:
        f.write(encrypted_data)

def decrypt_file(key, encrypted_file_path, decrypted_file_path):
    try:
        with open(encrypted_file_path, 'rb') as f:
            encrypted_data = f.read()

        cipher = Fernet(key)
        decrypted_data = cipher.decrypt(encrypted_data)

        with open(decrypted_file_path, 'wb') as f:
            f.write(decrypted_data)
    except InvalidToken:
        print("Invalid token. Decryption failed.")

def backup_directory(source_dir, dest_dir, key):
    for root, dirs, files in os.walk(source_dir):
        for file in files:
            file_path = os.path.join(root, file)
            encrypt_file(key, file_path)
            shutil.move(file_path + '.encrypted', os.path.join(dest_dir, file + '.encrypted'))

def restore_backup(backup_dir, dest_dir, key):
    for root, dirs, files in os.walk(backup_dir):
        for file in files:
            file_path = os.path.join(root, file)
            if file_path.endswith('.encrypted'):
                decrypt_file(key, file_path, os.path.join(dest_dir, file[:-10])) # remove '.encrypted' from file name


# Example usage:
key = generate_key()
source_dir = '/Users/adisankarlalan/Desktop/odd semester resources'
dest_dir = '/Users/adisankarlalan/Desktop/'

# Backup
backup_directory(source_dir, dest_dir, key)

# Restore
restored_dir = '/Users/adisankarlalan/Desktop/coom'
restore_backup(dest_dir, restored_dir, key)
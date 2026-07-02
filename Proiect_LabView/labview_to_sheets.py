
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import sys

scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]

json_keyfile = "proiect-impm-01ec767dab9d.json"

creds = ServiceAccountCredentials.from_json_keyfile_name(json_keyfile, scope)
client = gspread.authorize(creds)

spreadsheet_name = "PROIECT SDM"

sheet = client.open(spreadsheet_name).sheet1

args = sys.argv[1:]

sheet.append_row(args)

import yfinance as yf
import time

def display_amazon_stock_price():
    amazon_ticker = 'AMZN'
    while True:
        data = yf.download(amazon_ticker, period='1d', interval='1m')
        latest_data = data['Close'].iloc[-1]
        print(f"\n--- Valeur d'Amazon ({amazon_ticker}) en temps réel ---")
        print(f"Prix de clôture: {latest_data}")
        time.sleep(5)  # Mettre à jour toutes les 5 secondes

if __name__ == "__main__":
    display_amazon_stock_price()

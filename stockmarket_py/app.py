from flask import Flask, render_template, jsonify
import yfinance as yf

app = Flask(__name__)

@app.route('/')
def home():
    tickers = ['^FCHI', 'MSFT', 'AAPL', 'GOOGL', 'MC.PA', 'TSLA', 'META']
    data = {ticker: get_stock_data(ticker) for ticker in tickers}
    return render_template('index.html', data=data)

@app.route('/stock_data/<ticker>')
def stock_data(ticker):
    data = get_stock_data(ticker)
    return jsonify(data)

def get_stock_data(ticker):
    try:
        data = yf.download(ticker, period='1d', interval='1m')
        latest_data = data['Close'].iloc[-1]
        stock_data = {
            'symbol': ticker,
            'price': latest_data
        }
    except KeyError:
        stock_data = {
            'symbol': ticker,
            'price': 'Données en cours de Chargement : ' + ticker
        }
    return stock_data

if __name__ == '__main__':
    app.run(debug=True)

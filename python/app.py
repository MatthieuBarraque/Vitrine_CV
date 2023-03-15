from flask import Flask, render_template, jsonify
import yfinance as yf

app = Flask(__name__)

@app.route('/')
def home():
    data = get_amazon_stock_price()
    return render_template('index.html', data=data)

@app.route('/amazon_stock_price')
def amazon_stock_price():
    data = get_amazon_stock_price()
    return jsonify(data)

def get_amazon_stock_price():
    amazon_ticker = 'AMZN'
    data = yf.download(amazon_ticker, period='1d', interval='1m')
    latest_data = data['Close'].iloc[-1]
    stock_data = {
        'symbol': amazon_ticker,
        'price': latest_data
    }
    return stock_data

if __name__ == '__main__':
    app.run(debug=True)
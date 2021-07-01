const { join, resolve } = require('path');
const webpack = require('webpack');

module.exports = {
  entry: resolve(__dirname, './src/index.js'),
  output: {
    filename: 'bundle.js',
    path: resolve(__dirname, './public')
  },
  module: {
    rules: [
      {
        test: /\.(js)$/,
        loader: 'babel-loader',
        exclude: /node_modules/
      }
    ]
  },
  devServer: {
    contentBase: resolve(__dirname, './public')
  },
  plugins: [
      new webpack.ProvidePlugin({
          $: 'jquery',
          'JQuery': 'jquery',
          'Backbone': 'backbone',
          _: 'underscore'
      })
  ]
};

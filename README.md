<p><H3>Si4703ブレークアウト基板によるFMラジオ</H3></p>
<p>
Si4703は、SiliconLab製のFM対応のDSPラジオICである。SparkFunがブレークアウト基板化した物の中華コピーが安い価格で出回っている。<br>
I2Cインターフェースでコントロールでき、Arduinoとの組み合わせが可能である。<br>
ただ電圧が3.3V対応なので、5VのArduinoと接続するためには信号レベルの電圧変換が必要である。<br>
ここでは、ATmega328pを3.3Vでドライブすることで電圧変換回路を省略した(動作は保証されていない)。<br>
基板の概要、回路図、データシートは、<a href="https://www.switch-science.com/catalog/2655/">こちら（評価モジュール）</a>を参考にするとよい。<br>
150mWのアンプが搭載されているので小型のスピーカは鳴らせる。なお、アンテナはオーディオケーブルを兼用する仕組みになっている。<br>
Si4703のライブラリは<a href="https://github.com/sparkfun/Si4703_FM_Tuner_Evaluation_Board/tree/V_H1.3_L1.2.0">GitHub（DSPラジオモジュール）</a>を参考にするとよい。<br>
</p>

<p><strong>特長</strong><br>
必要最小限の構成にしている。<br>
  ・タクトスイッチ１にて受信局（局名、周波数をハードコードしておく）を切り替える。<br>
 ・タクトスイッチ２，３にてボリュームを調節する。<br>
 ・受信局名と周波数、ボリューム値をOLEDに表示可能。<br>
 ・受信局とボリューム値はスイッチOFFしてもEEPROMに記憶している。<br>
</p>
<p><strong>H/W構成</strong><br>
 ・ATmega328p - コントローラ<br>
 ・SD1306 128x64 OLED表示装置（オプション）<br>
 ・タクトスイッチ１、タクトスイッチ２、タクトスイッチ３<br>
 ・Xtal発振器（16MHz）、コンデンサ・抵抗類
</p>
<p>
<img src="./SI4703_BRK_1.jpg" width="480" height="360">
FM 85.2MHzを受信中
</p>
<p><strong>操作</strong><br>
 ・プリセットしたラジオ局又は受信周波数の切り替え（タクトスイッチ）。<br>
 ・音量調整（タクトスイッチ）。<br>
</p>
<p><strong>接続</strong><br>
各コンポーネントの接続は以下の通り。<br>
</p>
<p>
I2C接続&nbsp; Si4703と表示装置（マルチドロップで接続）<br>
※内蔵のプルアップ機能を利用しているのでプルアップ抵抗は不要<br>
<table> 
<tr>
<td>I2C&nbsp;</td><td>ATmega328p</td><td>&nbsp;ピン</td>
</tr>
<tr>
<td>VCC</td><td>VCC(3.3V)</td><td>7</td>
</tr>
<tr>
<td>GND</td><td>GND</td><td>8</td>
</tr>
<tr>
<td>SCK</td><td>A5</td><td>28</td>
<tr>
<tr>
<td>SDA</td><td>A4</td><td>27</td>
<tr>
</table>
</p>
<p>
タクトスイッチ（ボタン）
<table> 
<tr>
<td>ボタン&nbsp;</td><td>ATmega328p&nbsp;</td><td>&nbsp;ピン</td><td>&nbsp;機能</td>
</tr>
<tr>
<td>STATION</td><td>D3</td><td>5</td><td>ラジオ局を「次へ」切り替え</td>
</tr>
<tr>
<td>VOL+</td><td>D4</td></td><td>6</td><td>音量大</td>
</tr>
<tr>
<td>VOL-</td><td>D5</td><td>11</td><td>音量小</td>
<tr>
</table>
</p>
<p><strong>インストール</strong><br>
<ol>
<li>コードを、ZIP形式でダウンロード</li>
<li>ArduinoIDEにおいてライブラリを登録</li>
<li>ArduinoIDEからsi4703_breakout_oled_master.inoを開く</li>
<li>「検証・コンパイル」に成功したら、一旦、「名前を付けて保存」を行う<br>
（ライブラリが不足のエラーが出たら、追加する。例えば、SD1306 OLED表示装置<br>
(IDEのライブラリマネージャにおいてU8glibを検索)）<br>
</li>
<li>関数updatestation()において、受信したいローカルのFM局の局名と周波数を設定する</li>
<li>関数station_setting()において、受信したいローカルのFM局のmax局数を変更する</li>
<li>なお、動作の状況がシリアルモニタに表示される（9600ボー）</li>
</li>
</ol>
</p>
<p>
<p><strong>若干の解説</strong><br>
・Si4703のライブラリ（Si4703_Breakout.cpp）は受信範囲を拡大(76-108Mhz)するため<br>
オリジナルのコードを変更している（行30、行152）。<br>
・受信局の変更ついては、割り込み機能を利用している。例&nbsp;void station_setting()<br>
・Atmega328pをArduinoとして使うことに関しては<a href="https://ht-deko.com/arduino/atmega328p.html">こちら</a>を参考にするとよい。<br>
</p>
<p>
<img src="./SI4703_BRK_2.jpg" width="450" height="400">
基板上の配置の様子。右がAtmega328p、左がSi4703基板。電源はUSB、AMS1117-3.3により3.3Vに変換している。
</p>
<p><strong>注意事項</strong><br>
・通常、電圧を3.3Vにすると8MHz動作が仕様であるが、幸運なことに、このチップは16MHzでも動作している。<br>
ただ、火花雑音（近傍でのスイッチON/OFF）を拾い誤動作することがある。<br>
・受信するFM局が多い場合は、タクトスイッチを1個増やして（2つ目の割り込みとする）、UP&DOWNにすることをお勧めする。<br>
・利用の際は、自己責任でお楽しみください。<br>
</p>

<p><H3>Si4703�u���[�N�A�E�g��ɂ��FM���W�I</H3></p>
<p>
Si4703�́ASiliconLab����FM�Ή���DSP���W�IIC�ł���BSparkFun���u���[�N�A�E�g����������̒��؃R�s�[���������i�ŏo����Ă���B<br>
I2C�C���^�[�t�F�[�X�ŃR���g���[���ł��AArduino�Ƃ̑g�ݍ��킹���\�ł���B<br>
�����d����3.3V�Ή��Ȃ̂ŁA5V��Arduino�Ɛڑ����邽�߂ɂ͐M�����x���̓d���ϊ����K�v�ł���B<br>
�����ł́AATmega328p��3.3V�Ńh���C�u���邱�Ƃœd���ϊ���H���ȗ�����(����͕ۏ؂���Ă��Ȃ�)�B<br>
��̊T�v�A��H�}�A�f�[�^�V�[�g�́A<a href="https://www.switch-science.com/catalog/2655/">������i�]�����W���[���j</a>���Q�l�ɂ���Ƃ悢�B<br>
150mW�̃A���v�����ڂ���Ă���̂ŏ��^�̃X�s�[�J�͖点��B�Ȃ��A�A���e�i�̓I�[�f�B�I�P�[�u�������p����d�g�݂ɂȂ��Ă���B<br>
Si4703�̃��C�u������<a href="https://github.com/sparkfun/Si4703_FM_Tuner_Evaluation_Board/tree/V_H1.3_L1.2.0">GitHub�iDSP���W�I���W���[���j</a>���Q�l�ɂ���Ƃ悢�B<br>
</p>

<p><strong>����</strong><br>
�K�v�ŏ����̍\���ɂ��Ă���B<br>
  �E�^�N�g�X�C�b�`�P�ɂĎ�M�ǁi�ǖ��A���g�����n�[�h�R�[�h���Ă����j��؂�ւ���B<br>
 �E�^�N�g�X�C�b�`�Q�C�R�ɂă{�����[���𒲐߂���B<br>
 �E��M�ǖ��Ǝ��g���A�{�����[���l��OLED�ɕ\���\�B<br>
 �E��M�ǂƃ{�����[���l�̓X�C�b�`OFF���Ă�EEPROM�ɋL�����Ă���B<br>
</p>
<p><strong>H/W�\��</strong><br>
 �EATmega328p - �R���g���[��<br>
 �ESD1306 128x64 OLED�\�����u�i�I�v�V�����j<br>
 �E�^�N�g�X�C�b�`�P�A�^�N�g�X�C�b�`�Q�A�^�N�g�X�C�b�`�R<br>
 �EXtal���U��i16MHz�j�A�R���f���T�E��R��
</p>
<p>
<img src="./SI4703_BRK_1.jpg" width="480" height="360">
FM 85.2MHz����M��
</p>
<p><strong>����</strong><br>
 �E�v���Z�b�g�������W�I�ǖ��͎�M���g���̐؂�ւ��i�^�N�g�X�C�b�`�j�B<br>
 �E���ʒ����i�^�N�g�X�C�b�`�j�B<br>
</p>
<p><strong>�ڑ�</strong><br>
�e�R���|�[�l���g�̐ڑ��͈ȉ��̒ʂ�B<br>
</p>
<p>
I2C�ڑ�&nbsp; Si4703�ƕ\�����u�i�}���`�h���b�v�Őڑ��j<br>
�������̃v���A�b�v�@�\�𗘗p���Ă���̂Ńv���A�b�v��R�͕s�v<br>
<table> 
<tr>
<td>I2C&nbsp;</td><td>ATmega328p</td><td>&nbsp;�s��</td>
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
�^�N�g�X�C�b�`�i�{�^���j
<table> 
<tr>
<td>�{�^��&nbsp;</td><td>ATmega328p&nbsp;</td><td>&nbsp;�s��</td><td>&nbsp;�@�\</td>
</tr>
<tr>
<td>STATION</td><td>D3</td><td>5</td><td>���W�I�ǂ��u���ցv�؂�ւ�</td>
</tr>
<tr>
<td>VOL+</td><td>D4</td></td><td>6</td><td>���ʑ�</td>
</tr>
<tr>
<td>VOL-</td><td>D5</td><td>11</td><td>���ʏ�</td>
<tr>
</table>
</p>
<p><strong>�C���X�g�[��</strong><br>
<ol>
<li>�R�[�h���AZIP�`���Ń_�E�����[�h</li>
<li>ArduinoIDE�ɂ����ă��C�u������o�^</li>
<li>ArduinoIDE����si4703_breakout_oled_master.ino���J��</li>
<li>�u���؁E�R���p�C���v�ɐ���������A��U�A�u���O��t���ĕۑ��v���s��<br>
�i���C�u�������s���̃G���[���o����A�ǉ�����B�Ⴆ�΁ASD1306 OLED�\�����u<br>
(IDE�̃��C�u�����}�l�[�W���ɂ�����U8glib������)�j<br>
</li>
<li>�֐�updatestation()�ɂ����āA��M���������[�J����FM�ǂ̋ǖ��Ǝ��g����ݒ肷��</li>
<li>�֐�station_setting()�ɂ����āA��M���������[�J����FM�ǂ�max�ǐ���ύX����</li>
<li>�Ȃ��A����̏󋵂��V���A�����j�^�ɕ\�������i9600�{�[�j</li>
</li>
</ol>
</p>
<p>
<p><strong>�኱�̉��</strong><br>
�ESi4703�̃��C�u�����iSi4703_Breakout.cpp�j�͎�M�͈͂��g��(76-108Mhz)���邽��<br>
�I���W�i���̃R�[�h��ύX���Ă���i�s30�A�s152�j�B<br>
�E��M�ǂ̕ύX���ẮA���荞�݋@�\�𗘗p���Ă���B��&nbsp;void station_setting()<br>
�EAtmega328p��Arduino�Ƃ��Ďg�����ƂɊւ��Ă�<a href="https://ht-deko.com/arduino/atmega328p.html">������</a>���Q�l�ɂ���Ƃ悢�B<br>
</p>
<p>
<img src="./SI4703_BRK_2.jpg" width="450" height="400">
���̔z�u�̗l�q�B�E��Atmega328p�A����Si4703��B�d����USB�AAMS1117-3.3�ɂ��3.3V�ɕϊ����Ă���B
</p>
<p><strong>���ӎ���</strong><br>
�E�ʏ�A�d����3.3V�ɂ����8MHz���삪�d�l�ł��邪�A�K�^�Ȃ��ƂɁA���̃`�b�v��16MHz�ł����삵�Ă���B<br>
�����A�ΉԎG���i�ߖT�ł̃X�C�b�`ON/OFF�j���E���듮�삷�邱�Ƃ�����B<br>
�E��M����FM�ǂ������ꍇ�́A�^�N�g�X�C�b�`��1���₵�āi2�ڂ̊��荞�݂Ƃ���j�AUP&DOWN�ɂ��邱�Ƃ������߂���B<br>
�E���p�̍ۂ́A���ȐӔC�ł��y���݂��������B<br>
</p>

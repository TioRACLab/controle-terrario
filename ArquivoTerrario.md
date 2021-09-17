# Arquivo de configuração

O Arquivo de configuração do Sistema do terrário, usado se o módulo SD estiver ativo, usa o arquivo raiz chamado 'terrario.bin'.

## Estrutura do Arquivo

<table>
    <thead>
        <tr>
            <td>Título</td>
            <td>Byte</td>
            <td>Descrição</td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan="5">Iluminação</td>
            <td>0</td>
            <td>Dias da semana que o sistema de iluminação deve ligar.</td>
        </tr>
        <tr>
            <td>1</td>
            <td>Hora início que a iluminação deve ligar.</td>
        </tr>
        <tr>
            <td>2</td>
            <td>Minuto início que a iluminação deve ligar.</td>
        </tr>
        <tr>
            <td>3</td>
            <td>Hora fim que a iluminação deve desligar.</td>
        </tr>
        <tr>
            <td>4</td>
            <td>Minuto fim que a iluminação deve desligar.</td>
        </tr>
        <tr>
            <td rowspan="5">Luz de Espectro</td>
            <td>5</td>
            <td>Dias da semana que o sistema de luz de espectro deve ligar.</td>
        </tr>
        <tr>
            <td>6</td>
            <td>Hora início que a luz de espectro deve ligar.</td>
        </tr>
        <tr>
            <td>7</td>
            <td>Minuto início que a luz de espectro deve ligar.</td>
        </tr>
        <tr>
            <td>8</td>
            <td>Hora fim que a luz de espectro deve desligar.</td>
        </tr>
        <tr>
            <td>9</td>
            <td>Minuto fim que a luz de espectro deve desligar.</td>
        </tr>
        <tr>
            <td rowspan="5">Cascata</td>
            <td>10</td>
            <td>Dias da semana que o sistema de cascata deve ligar.</td>
        </tr>
        <tr>
            <td>11</td>
            <td>Hora início que a cascata deve ligar.</td>
        </tr>
        <tr>
            <td>12</td>
            <td>Minuto início que a cascata deve ligar.</td>
        </tr>
        <tr>
            <td>13</td>
            <td>Hora fim que a cascata deve desligar.</td>
        </tr>
        <tr>
            <td>14</td>
            <td>Minuto fim que a cascata deve desligar.</td>
        </tr>
        <tr>
            <td rowspan="5">Irrigação</td>
            <td>15</td>
            <td>Dias da semana que o sistema de irrigação deve ligar.</td>
        </tr>
        <tr>
            <td>16</td>
            <td>Hora início que a irrigação deve ligar.</td>
        </tr>
        <tr>
            <td>17</td>
            <td>Minuto início que a irrigação deve ligar.</td>
        </tr>
        <tr>
            <td>18</td>
            <td>Hora fim que a irrigação deve desligar.</td>
        </tr>
        <tr>
            <td>19</td>
            <td>Minuto fim que a irrigação deve desligar.</td>
        </tr>
        <tr>
            <td rowspan="5">Neblina</td>
            <td>20</td>
            <td>Dias da semana que o sistema de neblina deve ligar.</td>
        </tr>
        <tr>
            <td>21</td>
            <td>Hora início que a neblina deve ligar.</td>
        </tr>
        <tr>
            <td>22</td>
            <td>Minuto início que a neblina deve ligar.</td>
        </tr>
        <tr>
            <td>23</td>
            <td>Hora fim que a neblina deve desligar.</td>
        </tr>
        <tr>
            <td>24</td>
            <td>Minuto fim que a neblina deve desligar.</td>
        </tr>
    </tbody>
</table>
## 1. GPIO Yapılandırması (gpio_config Fonksiyonu)

```c
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
```
* **RCC_PeriphClockCmd :** GPIOA pinleri için AHB1 bus'ındaki clock sinyalini aktif eder.
* **GPIOA :** PA2 ve PA3 pinleri USART2 için kullanılacak. (Bu uygulamada sadece terminal TX pini kullanılmıştır.)

```c
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
```
* **GPIO_PinAFConfig :** GPIO pinini alternatif fonksiyon (AF) moduna ayarlar.
  * PA2 pini USART_TX için ayarlanıyor.

```c
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
```
* **GPIO_Mode_AF     :** Pin, alternatif fonksiyon (USART) olarak çalışır.
* **GPIO_OType_PP    :** Push-Pull modu kullanılır.
* **GPIO_Pin         :** PA2 (USART2_TX) ve PA3 (USART2_RX) pinleri seçiliyor.
* **GPIO_PuPd_NOPULL :** Pin için pull-up veya pull-down direnci devre dışı.
* **GPIO_Speed_50MHz :** GPIO'nun çalışma hızı 50 MHz olarak belirleniyor.

```c
GPIO_Init(GPIOA, &GPIO_InitStruct);
```
* **GPIO_Init :** Yapılandırma parametreleri kullanılarak GPIOA pinleri başlatılır.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 2. USART Yapılandırması (usart_config Fonksiyonu)

```c
RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
```
* **RCC_APB1PeriphClockCmd :** USART2 modülüne APB1 bus üzerinden clock sinyali sağlar.

```c
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
```
* **USART_BaudRate             :** Haberleşme hızını 115200 baud olarak ayarlar.
* **USART_HardwareFlowControl  :** Donanımsal akış kontrolü kullanılmaz.
* **USART_Mode_Tx              :** Sadece veri gönderme modu etkin.
* **USART_Parity_No            :** Veri çerçevesinde parite biti kullanılmaz.
* **USART_StopBits_1           :** Stop bit sayısı 1 olarak ayarlanır.
* **USART_WordLength_8b        :** Veri uzunluğu 8 bit olarak seçilir.

```c
USART_Init(USART2, &USART_InitStruct);
USART_Cmd(USART2, ENABLE);
```
* **USART_Init :** USART2  yapılandırmasını tamamlar.
* **USART_Cmd  :** USART2 modülü aktif eder.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 3. Karakter Dizisini USART ile Gönderme (usart_puts Fonksiyonu)

```c
void usart_puts(USART_TypeDef* USARTx, volatile char *str)
{
	while (*str)
	{
		while (!(USARTx->SR & 0x00000040));
		USART_SendData(USARTx, *str);
		*str++;
	}
}
```
* **while (\*str)                      :** String'in sonuna (null karaktere) ulaşana kadar döner.
* **while (!(USARTx->SR & 0x00000040)) :** TXE (Transmit Data Register Empty) biti 1 olana kadar bekler. Bu, veri gönderilmeye hazır olduğunu gösterir.
* **USART_SendData                     :** USART üzerinden bir byte veri gönderir.
* **\*str++                            :** String'in bir sonraki karakterine geçer.  






















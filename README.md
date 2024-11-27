# UART_in_STM32F446RE_NUCLEO

## USART

* USART (Universal Synchronous - Asynchronous Receiver - Transmitter) 1 ve 0 lardan oluşan verileri, iki dijital sistem arasında alıp - verme işleminde kullanılan bir iletişim protokolüdür.
* Dijital sistemlerde iletişim paralel ve seri olmak üzere iki türlü yapılır. Paralel iletişimde bilgi vericiden alıcıya aynı anda birden fazla bit gidecek şekilde gönderilir. Böylece tek hamlede birden fazla veri karşı tarafa gönderildiği için iletişim hızı yüksektir. Fakat bu iletişim türünde kullanılan hat sayısı fazladır ve uzun mesafeler için uygun değildir.
* Seri iletişimde ise vericiden alıcıya gönderilecek bilgi, tek hat üzerinden sırayla gönderilir. Bu şekilde giden bilginin, tek hamlede tek biti gönderilebileceği için iletişim hızı yavaştır. Fakat seri iletişimde hat sayısı azdır ve uzun mesafeli iletişim için daha uygundur.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

* USART protokolü bir seri iletişim protokolüdür. Usart protokolünde veriler senkron veya asenkron olarak alınabilirler. Senkron veri alışverişinde bir data hattı ve bir clock hattı bulunmalıdır. Data hattından gidecek veriler, clock hattından gönderilen sinyalin her düşen veya yükselen kenarında alıcıya iletilir.

* Asenkron modda ise verilerin iletilmesinde bir clock hattına ihtiyaç duyulmaz. Verilerin gönderilmeye başlayacağı, alıcıya bir başlangıç (start) sinyali ile bildirilir ve hemen arkasından veriler akmaya başlar. Burada verilerin gönderim ve alım hızının zamanlanması, alıcının her gelen biti algılayabilmesi açısından çok önemlidir.

* Asenkron seri iletişimde verinin gönderilmeye başlayacağını bildiren bir start biti, verinin gönderilmesinin bittiğini belirten bir stop biti, bir de verilerin doğru olarak gönderilip  gönderilmediğini anlamak için kullanılan "parity (eşitlik)" biti bulunmaktadır. Veri bitleri ise 7 veya 8 bit olabilir.
  * Parity bitinin gönderilmesi şart değildir.

* Asenkron iletişimde kullanılan diğer bir kavram ise veri gönderim hızıdır. Bu kavram "bps" (bits per second - saniyede gönderilen bit sayısı) birimi ile anılır. Standart veri gönderme hızları 110, 150, 300, 600, 1200, 2400, 4800, 9600, 56000, 115200 gibi hızlardır.

* Start biti "0", stop biti "1" verilerinden oluşmaktadır.







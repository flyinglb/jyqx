//Room: jietuopo.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���������
Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����ã�����һƬ��
�֡�����ɽϪ�����ʵ������µ����档
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"milin2",
          "westup"    : __DIR__"guanyintang",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

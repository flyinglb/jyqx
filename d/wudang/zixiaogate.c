//Room: zixiaogonggate.c ����������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����������");
      set("long",@LONG
�����ߵ���չ����£�ǰ������䵱ɽ��Ϊ���Ĺ����������ˡ�
������ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ����
���������䵱ʦͽ����Ҫ�������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shijie2",
          "southup"    : __DIR__"guangchang",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

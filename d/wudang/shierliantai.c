//Room: shierliantai.c ʮ����̨
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʮ����̨");
      set("long",@LONG
�������䵱������ʮ����̨��̨��̨֮����������������̾�������Զ��
��������ڡ�վ����̨��������������ǧҶ����֮�ϣ�ǧ�����ֶ��ڽ��¡���
���������߰�����Ļ�ɽ��������ˮ�������塢��һ�������۵ס�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

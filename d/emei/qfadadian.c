//Room: qfadadian.c ǧ���ִ��
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","ǧ���ִ��");
      set("long",@LONG
ǧ���ֵ���߹���������ׯ�ϡ�������һ������ǧ�����ƣ�����������
���ڵ��壬���з��������������У����ƾ����ޱȡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/hui" : 1,
           CLASS_D("emei") + "/wenyin" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"      : __DIR__"qianfoan",
          "east"     : __DIR__"qfachanfang",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

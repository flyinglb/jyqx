//Room: qingyinge.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","������");
      set("long",@LONG
�����Ƕ���ɽ�������󡣴˸�λ��ţ�����£����а����������к�������
����֮ˮ�������������¡������й����������ֿ�������������������˫��
�š���������������һ���׸ߵĺں�ɫ��ʯ��Ȼͦ��������ţ�ģ���֮Ϊ��ţ
��ʯ�����ű�����һʯ��(shibei)���ɴ������ϣ������Ǻ�����ջ������·��
����������ȥ�з��¡�
LONG);
      set("outdoors", "emei");
      set("objects", ([
           CLASS_D("emei") + "/xian" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"bailongdong",
          "southwest" : __DIR__"heilong1",
          "southeast" : __DIR__"zhongfengsi",
      ]));
//      set("no_clean_up", 0);
      setup();
}

string look_shibei()
{
        return


"ʯ������һʫԻ��\n\n"
"���������������� Ȼ �� �� �� �� ����\n\n"
"���������������� �� �� �� �� �� �١�\n\n"
"���������������� �� ˫ Ϫ һ �� ����\n\n"
"���������������� �� �� ˮ �� ţ �ġ�\n\n"
"����ǡ�����ʮ��ʫ����רӽ�⡰˫����������ʫ��\n";
}

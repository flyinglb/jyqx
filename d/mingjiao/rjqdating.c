//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���������Ĵ�������Ȼ��������֮�ˣ�����ȴ���õù�
ɫ���㣬�Գ����������ڲ�ͬ�������������һ�����ң���
���ĸ��̽���֡�������硱��һ�ٶ�ʮ��ǰ��������������
�ɹž���һ����ս����������������£����߰ˡ��ţ�������
������������ڣ�������Դ�Ϊ����֮�ס���������в輸��
���������ʹׯ�������������ڶ�һ�����
LONG );
	set("exits", ([
		"south" : __DIR__"rjqyuan",
	]));
//	set("outdoors", "mingjiao");
        set("objects",([
                __DIR__"npc/zhuangzheng":1,
//              "/kungfu/class/mingjiao/zhuangzheng":1,
//		"/kungfu/class/mingjiao/yangxiao":1,
//	        "/kungfu/class/mingjiao/fanyao":1,
//	        "/kungfu/class/mingjiao/yintianzheng":1,
//              "/kungfu/class/mingjiao/xiexun":1,
//	        "/kungfu/class/mingjiao/xuan-nan":1,
//              "/kungfu/class/mingjiao/weiyixiao":1,
	]));
	setup();
	replace_program(ROOM);
}

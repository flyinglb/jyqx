// Room: mishi.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", 

"���ǰ�����͵͵Ϊ��͵������·���ĵ�����ͨ����ͨ�����еĹ���塣

"HIY+"���ݿ͵�  -A1 ��������  -A2 ���ݲ��  -A3 �����͵�  -A4 �ɶ��͵�  -A5
���ݿ͵�  -A6 ���ݿ͵�  -A7 ���ݿ͵�  -A8 �����͵�  -A9 һƷ�ô�Ժ-A0"HIR+"
���ִ��۵�-B1 ����ɽ��  -B2 �䵱�����-B3 ��ü������-B4 ����ɷ��-B5
��ɽ����Ժ-B6 ̩ɽ�չ۷�-B7 ��ɽ��Ϊ��-B8 ��ɽף�ڵ�-B9 ��ɽ������-B0"HIG+"
��������  -C1 ؤ������  -C2 ؤ��С��  -C3 ���̹㳡  -C4 �������  -C5
��ػ�    -C6 Ѫ����ɽ��-C7 ���͵�����-C8 ����ׯ    -C9 �컨��    -C0"HIM+"
ȫ��������-D1 ��Ĺ����  -D2 �һ�������-D3 ���մ���  -D4 ����������-D5
����ɽС��-D6 ��ң���ƺ-D7 ���շ����-D8 ���޺�    -D9 ѩɽ�´��-D0"HIB+"
����      -E1 ����      -E2 ��ʦ�����-E3 ��ʦ��Ϣ��-E4 �����    -E5\n"NOR 

	);
	set("exits", ([
		"west" : __DIR__"workroom",
		"a1"  : "/d/city/kedian",
		"a2"  : "/d/city/wumiao",
		"a3"  : "/d/city/chaguan",
		"a4"  : "/d/city2/kedian",
		"a5"  : "/d/city3/kedian",
		"a6"  : "/d/suzhou/kedian",
		"a7"  : "/d/hangzhou/kedian",
		"a8"  : "/d/fuzhou/rongcheng",
		"a9"  : "/d/xiangyang/kedian",
		"a0"  : "/d/lingzhou/yipindayuan",

		"b1"  : "/d/shaolin/dxbdian",
		"b2"  : "/d/shaolin/guangchang1",
		"b3"  : "/d/wudang/sanqingdian",
		"b4"  : "/d/emei/hcaguangchang",
		"b5"  : "/d/qingcheng/songfengguan",
		"b6"  : "/d/songshan/chanyuan",
		"b7"  : "/d/taishan/riguan",
		"b8"  : "/d/huashan/buwei3",
		"b9"  : "/d/henshan/zhurongdian",
		"b0"  : "/d/hengshan/baiyunan",

		"c1"  : "/d/dali/wangfugate",
		"c2"  : "/d/city/pomiao",
		"c3"  : "/d/city/gbxiaowu",
		"c4"  : "/d/mingjiao/square",
		"c5"  : "/d/heimuya/chengdedian",
		"c6"  : "/d/city2/dating",
		"c7"  : "/d/xuedao/shandong3",
		"c8"  : "/d/xiakedao/dating",
		"c9"  : "/d/guiyun/qianyuan",
		"c0"  : "/d/hangzhou/liuhed",

		"d1"  : "/d/quanzhen/datang1",
		"d2"  : "/d/gumu/zhengting",
		"d3"  : "/d/taohua/dating",
		"d4"  : "/d/baituo/dating",
		"d5"  : "/d/shenlong/dating",
		"d6"  : "/d/huashan/xiaowu",
		"d7"  : "/d/xiaoyao/qingcaop",
		"d8"  : "/d/lingjiu/dating",
		"d9"  : "/d/xingxiu/xxh2",
		"d0"  : "/d/xueshan/dadian",

		"e1"  : "/d/death/god2",
		"e2"  : "/d/death/gate",
		"e3"  : "/d/wizard/guest_room",
		"e4"  : "/d/wizard/wizard_room",
		"e5"  : "/d/city/wudao4",
	]));
	set("valid_startroom","1");
	setup();
	replace_program(ROOM);
}

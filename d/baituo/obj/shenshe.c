//shenshe.c
inherit ITEM;
void create()
{
	set_name("��·����", ({ "shen she", "snake"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ʶ·���������ߣ����԰����˴�����
		      ��ɽ��(��Ҽ���home����)\n");
		set("unit", "��");
		set("value", 0);
	}
}
void init()
{
	add_action("do_home","home");
}
int do_home()
{
//        string dir;
	object me = this_player();

//if( !SKILL_D(skill_name[item])->valid_learn(me) )
//return SKILL_D(skill_name[item])->valid_learn(me);
        if (!environment(me)->valid_leave(me,"up"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"down"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"enter"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"out"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"east"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"west"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"south"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"north"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"southeast"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"southwest"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"northeast"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"northwest"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"eastup"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"westup"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"southup"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"northup"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"eastdown"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"westdown"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"southdown"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
        if (!environment(me)->valid_leave(me,"northdown"))
		return notify_fail("������һ��͵����ʲô�����߲�����ʹ������\n");
	if(me->query("family/family_name") != "����ɽ��")
	return notify_fail("�㲻�ǰ���ɽ�ɵ��ӣ�����·���ߡ�������ʹ����\n");
	message_vision("$N�ӻ����ͳ�����·���ߡ������ﲻ֪����Щʲô��\n
	�ͼ�����·���ߡ�����о�ӣ�ҡͷ��β�ذ�$N������ɽ��ȥ������\n",me);
	me->move("/d/baituo/damen");
	return 1;
}

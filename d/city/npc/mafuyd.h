int do_rideyd()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat ��������"+ob->query("name")+
		"���"+RANK_D->query_rude(ob)+"��͵��\n");
		return 1;
	}
	switch (random(3))
	{
		case 1:
			hname=MAG"������"NOR;
			break;
		case 2:
			hname=RED"�����"NOR;
			break;
		default:
			hname=HIY"������"NOR;
			break;
	}
	message_vision(
"������ָ�$Nǣ��һƥ"+hname+"��$N����Ծ��������������������·������һ��
���: �����ޡ�\n"NOR , ob );
	message_vision("\nֻ��$N������һ�У�"+hname+"�����͵��ȥ��\n",ob);
	ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/caodi1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/caodi2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/shulin1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/shulin3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/tiandi1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/tiandi3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/tiandi4");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/huanghe1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/weifen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/huanghe_1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/hetao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/huangtu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/huanghe_2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/huanghe_3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/yongdeng");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}

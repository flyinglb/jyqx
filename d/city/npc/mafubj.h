int do_ridebj()
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
	ob->move("/d/shaolin/yidao1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/shaolin/yidao2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/shaolin/hanshui1");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"Ծ�뺺ˮ�з�������԰���\n", ({ob}));
	ob->move("/d/shaolin/hanshui2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/shaolin/nanyang");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/shaolin/yidao3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/shaolin/ruzhou");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road10");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road9");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road8");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road4");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road7");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road6");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/road5");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/yongding");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/nandaj2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/nandaj1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/city2/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�����ﱱ����\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}

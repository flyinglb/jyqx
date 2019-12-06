//chinese.c
//modify byp@jyqxz 2000.09.12

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��chinese [<Ӣ��> to <����>] | [-l <Ӣ��>] | [-d <Ӣ��>] \n");;
        
        if( sscanf(arg, "-l %s", key) ) {
                chinz = to_chinese(key);
                if(chinz == key)
                        write( "û���ҵ�������ʡ�\n");
                else
                        write( "���� " + key + " == " + chinz + "\n");
                return 1;
        }
	//���� dict �ĸĶ�Ҳ����Ҫ��¼
	if( sscanf(arg, "%s to %s", key, chinz) == 2 ) {
		CHINESE_D->add_translate(key, chinz);
		log_file("dict_modify", sprintf("add_dict %s %s to %s %s\n", geteuid(me), key, chinz, ctime(time())) );
		write( "���ӵ��� " + key + " to " + chinz + "\nOk.\n");
		return 1;
	}
	if( sscanf(arg, "-d %s", key) ) {
	        chinz = to_chinese(key);
	        CHINESE_D->remove_translate(key);
	        log_file("dict_modify", sprintf("del_dict %s %s == %s %s\n", geteuid(me), key, chinz, ctime(time())) );
	        write( "ɾ������  " + key + "\nOk.\n");
	        return 1;
	}
	return 0;
}

int help()
{
	write ( @HELP
ָ���ʽ��chinese [<Ӣ��> to <����>] | [-l <Ӣ��>] | [-d <Ӣ��>] 

���ָ����������Ӣ�Ķ����ĵķ��롣�����ӷ���ǰ������ -l <Ӣ��>
���г��Ƿ��з�������Ƿ����-d <Ӣ��> ��ɾ������(���ã�)��
HELP
	);
	return 1 ;
}

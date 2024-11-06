#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{

	t_list	*lst = ft_lstnew("ghi");
	ft_lstadd_front(&lst, ft_lstnew("def"));
	ft_lstadd_front(&lst, ft_lstnew("abc"));

	ft_lstadd_back(&lst, ft_lstnew("jkl"));

	printf("%d\n", ft_lstsize(lst));

	printf("%s\n", (char *) lst->content);
	printf("%s\n", (char *) lst->next->content);
	printf("%s\n", (char *) lst->next->next->content);

	printf("%s\n", (char *) ft_lstlast(lst)->content);

	ft_lstdelone(lst->next->next->next, free);


	return (0);
}

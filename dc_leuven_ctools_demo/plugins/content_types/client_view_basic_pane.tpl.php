<?php
/**
 * @file
 * Template file for the Client View content type plugin.
 *
 * Available variables:
 * - $variables: all stuff that you need
 */
?>

<h2>This is <strong><?php print $variables['configuration']?></strong> Client View.</h2>
<ul>
  <li>Name: <?php print $variables['client_context']->name?></li>
  <li>Last Name: <?php print $variables['client_context']->last_name?></li>
  <li>Age: <?php print $variables['client_context']->age?></li>
</ul>
